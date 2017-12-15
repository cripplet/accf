package accf_structs

import (
	"github.com/cripplet/accf/protos/src"
)

type Ball struct {
	PB *accf_protos.Ball
}

func (self *Ball) GetLocale() Locale {
	return Locale{
		PB: self.PB.GetLocale(),
	}
}
