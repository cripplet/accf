package accf_analysis

import (
	"errors"
	"github.com/cripplet/accf/structs"
	"math"
)

// Calculates the pair-correlation function g(r) a.k.a. g2(r) of a
// particles-in-a-box configuration.
//
// N.B.: This function calculates the non-ensemble-averaged value of g(r).
// The normal definition calls for an average over possible canonical
// ensemble states (e.g. weighted by varying internal energy).
//
// Args:
//   box: The list of particles and the box dimentions. This function assumes
//     all particles are found within this box (i.e. does not consider
//     edge effects).
//   granularity: How finely the returned function can specify a particular
//     value of r.
//
// Returns:
//   A function with signature func(float64) (float64, error)
func GeneratePairCorrelationFunction2D(box accf_structs.Box, granularity float64) func(float64) (float64, error) {
	size := box.GetSize()

	radius_boundary := math.Max(size.X(), size.Y())
	n_shells := int(radius_boundary / granularity)

	histogram := make([]float64, n_shells)

	balls := box.GetBalls()
	for _, b1 := balls {
		l1 := b1.GetLocale()
		for _, b2 := balls {
			l2 := b2.GetLocale()
			l2.SetZ(l1.Z())
			histogram[int(l1.GetDistance(l2)/granularity)] += 1
		}
	}

	// Returns g(r) a.k.a. g2(r) of the specified particle configuration.
	//
	// Args:
	//   r: The interested radius, in the same units as the particle
	//    coordinates.
	//
	// Returns:
	//   Probabability of two particles separated by this distance in the
	//   configuration.
	return func(r float64) (float64, error) {
		shell := int(r / granularity)
		if shell >= len(histogram) {
			return 0, errors.New("Correlation undefined for such a large radius.")
		}
		return histogram[shell], nil
	}
}
