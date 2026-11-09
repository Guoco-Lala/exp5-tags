#include <iostream>
#include <string>

int main() {
	std::string sentence;
	std::cout << "请输入一句话：";
	std::getline(std::cin, sentence);

	// UTF-8 continuation bytes begin with the bit pattern 10xxxxxx.
	std::size_t count = 0;
	for (unsigned char byte : sentence) {
		if ((byte & 0xC0) != 0x80) {
			++count;
		}
	}

	std::cout << "字符个数：" << count << '\n';
	return 0;
}
