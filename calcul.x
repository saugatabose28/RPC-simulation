struct intpair {
	int a; 
	int b; 
}; 	
struct floatpair {
	float a; 
	float b; 
}; 	

program CALCULATION_PROG { 
	version CALCULATION_VERS1 { 
		int ADDD(intpair) = 1;
		int MULL(intpair) = 2; 
	} = 1; 
	version CALCULATION_VERS2 { 
		float ADDD(floatpair) = 1;
		float MULL(floatpair) = 2; 
	} = 2; 
} = 0x23451111;

