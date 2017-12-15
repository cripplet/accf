package accf_structs

import (
	"github.com/cripplet/accf/protos/src"
	"math"
)

type Locale struct {
	PB *accf_protos.Locale
}

func (self *Locale) ChangeCoordinateSystem(coordinate_system accf_protos.Locale_CoordinateSystem) *Locale {
	return nil
}

func (self *Locale) X() float64 {
	return self.PB.GetDimensions()[0]
}

func (self *Locale) Y() float64 {
	return self.PB.GetDimensions()[1]
}

func (self *Locale) Z() float64 {
	return self.PB.GetDimensions()[2]
}

func (self *Locale) SetX(x float64) {
	self.PB.Dimensions[0] = x
}

func (self *Locale) SetY(y float64) {
	self.PB.Dimensions[1] = y
}

func (self *Locale) SetZ(z float64) {
	self.PB.Dimensions[2] = z
}

func (self *Locale) GetDistance(other Locale) float64 {
	return math.Pow(math.Pow(other.X() - self.X(), 2) + math.Pow(other.Y() - self.Y(), 2) + math.Pow(other.Z() - self.Z(), 2), 0.5)
}
