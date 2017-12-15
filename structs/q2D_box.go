package accf_structs

import (
	"github.com/cripplet/accf/protos/src"
)

type Q2DBox struct {
	Box
	PB *accf_protos.Q2DBox
}

func (self *Q2DBox) CalculateCoverageCoverageRatio(locale Locale, r float64) float64 {
	return 0.0
}

func (self *Q2DBox) GetLocale() Locale {
	return Locale{
		PB: self.PB.GetSize(),
	}
}

func (self *Q2DBox) GetBalls() []Ball {
	balls := []Ball{}
	for _, b := range self.PB.GetBalls() {
		balls = append(balls, Ball{
			PB: b,
		})
	}
	return balls
}
