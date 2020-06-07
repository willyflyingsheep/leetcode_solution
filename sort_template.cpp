class sort_taolu {
public:
	return_type main(..) {

		auto cmp = [&](int a, int b) {
			return your_compare_condition();
		}

		// put the cmp to any data structure you need
		// e.g.
		sort(res_dt.begin(), res_dt.end(), cmp);

		return res_dt;
	}

}