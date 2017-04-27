#include <stdio.h>
#include <iostream>
using namespace std;

int conv(int x[]) {
	return x[0]-1 + (x[1]-1)*31 + x[2]*31*12;
}

int main(){
	int T, cu[4], bd[4];
	cin>>T;
	for (int cse=1; cse<=T; cse++) {
		scanf("%d/%d/%d %d/%d/%d", &cu[0],&cu[1],&cu[2], &bd[0],&bd[1],&bd[2]);
		float diff = (conv(cu) - conv(bd))/(31*12.0);
		printf("Case #%d: ", cse);
		if (diff<0) cout << "Invalid birth date\n";
		else if (diff>=131) cout << "Check birth date\n";
		else cout << (int)diff << endl;
	}
}
