while(low != high){
		mid = (low + high)/2;
		if(poss(mid)){
			high = mid;
		}else{
			low = mid + 1;
		}
	}