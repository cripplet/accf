package accf_structs

type Box interface {
	CalculateSphereCoverageRatio(Locale, float64) float64
	GetSize() Locale

	GetBalls() []Ball
}
