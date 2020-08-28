#ifndef _COMPNUM_H
#define _COMPNUM_H

class compnum {

	public:
		compnum();
		compnum(const compnum &);

		

	private:
		float mya;
		float myb;
};
compnum::compnum() {
	mya, myb = 0;
}
compnum::compnum(const compnum& Object) {
	mya = Object.mya;
	myb = Object.myb
}

#endif