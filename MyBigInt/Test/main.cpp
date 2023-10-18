#include <iostream>
#include "MyBigInt.h"
void test() {
	MyBigInt numberA;
	MyBigInt numberB;
	numberA.setHex("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
	if (numberA.getHex() == "51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4")
		std::cout << "Passed!" << '\n';
	else
		std::cout << "Fail!" << '\n';
	

	numberA.setHex("22e962951cb6cd2ce279ab0e2095825c");
	MyBigInt numberC = numberA.INV();
	if (numberC.getHex() == "dd169d6ae34932d31d8654f1df6a7da3")
		std::cout << "Passed!" << '\n';
	else
		std::cout << "Fail!" << '\n';


	numberA.setHex("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
	numberB.setHex("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");
	MyBigInt numberD = numberA.XOR(numberB);
	if (numberD.getHex() == "1182d8299c0ec40ca8bf3f49362e95e4ecedaf82bfd167988972412095b13db8")
		std::cout << "Passed!" << '\n';
	else
		std::cout << "Fail!" << '\n';


	numberA.setHex("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
	numberB.setHex("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");
	MyBigInt numberE = numberA.OR(numberB);
	if (numberE.getHex() == "51bff8ad9cafd72eabffbfc9befffffffcffbffaffdd779afdf3d7fdf7f73fbc")
		std::cout << "Passed!" << '\n';
	else
		std::cout << "Fail!" << '\n';


	numberA.setHex("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
	numberB.setHex("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");
	MyBigInt numberF = numberA.AND(numberB);
	if (numberF.getHex() == "403d208400a11322340808088d16a1b10121078400c1002748196dd62460204")
		std::cout << "Passed!" << '\n';
	else
		std::cout << "Fail!" << '\n';

	numberA.setHex("26A3C1BEC098F77B");
	MyBigInt numberG = numberA.shiftR(3);
	if (numberG.getHex() == "4d47837d8131eef")
		std::cout << "Passed!" << '\n';
	else
		std::cout << "Fail!" << '\n';

	numberA.setHex("36f028580bb02cc8272a9a020f4200e346e276ae664e45ee80745574e2f5ab80");
	numberB.setHex("70983d692f648185febe6d6fa607630ae68649f7e6fc45b94680096c06e4fadb");
	MyBigInt numberH = numberA.ADD(numberB);
	if (numberH.getHex() == "a78865c13b14ae4e25e90771b54963ee2d68c0a64d4a8ba7c6f45ee0e9daa65b")
		std::cout << "Passed!" << '\n';
	else
		std::cout << "Fail!" << '\n';
}
int main() {
	test();
	return 0;
}