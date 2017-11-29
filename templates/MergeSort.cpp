template<typename RAIteratorIn, typename RAIteratorOut>
int mergeSortImpl(RAIteratorIn iIn, RAIteratorOut iOut, int n)
{
	if (n < 2) return 0;

	auto iMid = iIn + n / 2;
	auto iEnd = iIn + n;
	auto iMidOut = iOut + n / 2;

	// make sorted 2 halves of In container
	int r = mergeSortImpl(iOut, iIn, iMid - iIn);
	int q = mergeSortImpl(iMidOut, iMid, iEnd - iMid);
	int recursionCount = 1 + max(r, q);

	// merge 2 halves into one
	auto iLeft = iIn, iRight = iMid;
	while (iLeft != iMid && iRight != iEnd)
	{
		if (*iLeft <= *iRight)
		{
			*iOut++ = *iLeft++;
		} else {
			*iOut++ = *iRight++;
		}
	}

	// copy elements that left after merging
	if (iLeft == iMid)
	{
		while (iRight != iEnd) *iOut++ = *iRight++;
	}
	else if (iRight == iEnd)
	{
		while (iLeft != iMid) *iOut++ = *iLeft++;
	}
	return recursionCount;
}

template<typename RAIterator>
void mergeSort(RAIterator from, RAIterator till)
{
	vector<int> u(from, till);

	int recursionCount = mergeSortImpl(from, u.begin(), u.size());

	if (recursionCount) swap_ranges(from, till, u.begin());
}