#include "Cornucopia/SimpleAPI.h" //just the simple API

int main()
{
	Cornu::Parameters params; //default values
	std::vector<Cornu::Point> pts;

	pts.push_back(Cornu::Point(100, 100));
	pts.push_back(Cornu::Point(120, 130));
	pts.push_back(Cornu::Point(140, 140));
	pts.push_back(Cornu::Point(300, 140));

	//pass it to the fitter and process it
	std::vector<Cornu::BasicPrimitive> result = Cornu::fit(pts, params);

	int nPrims[3] = { 0, 0, 0 };
	for(int i = 0; i < (int)result.size(); ++i)
		nPrims[result[i].type]++;

	printf("SimpleAPI Finished, #lines = %d, #arcs = %d, #clothoids = %d\n", nPrims[0], nPrims[1], nPrims[2]);
	std::vector<Cornu::BasicBezier> bezier = Cornu::toBezierSpline(result, 1.);
	printf("Conversion to Bezier results in %d segments\n", bezier.size());
	return 0;
}

