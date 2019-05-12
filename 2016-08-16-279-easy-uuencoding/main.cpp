#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::string uuencode(std::string, std::string);

std::string test = "I feel very strongly about you doing duty. "
	"Would you give me a little more documentation about your "
	"reading in French? I am glad you are happy - but I never "
	"believe much in happiness. I never believe in misery either. "
	"Those are things you see on the stage or the screen or the "
	"printed pages, they never really happen to you in life.";

std::string expected = "begin 644 file.txt\n"
	"M22!F965L('9E<GD@<W1R;VYG;'D@86)O=70@>6]U(&1O:6YG(&1U='DN(%=O\n"
	"M=6QD('EO=2!G:79E(&UE(&$@;&ET=&QE(&UO<F4@9&]C=6UE;G1A=&EO;B!A\n"
	"M8F]U=\"!Y;W5R(')E861I;F<@:6X@1G)E;F-H/R!)(&%M(&=L860@>6]U(&%R\n"
	"M92!H87!P>2 M(&)U=\"!)(&YE=F5R(&)E;&EE=F4@;75C:\"!I;B!H87!P:6YE\n"
	"M<W,N($D@;F5V97(@8F5L:65V92!I;B!M:7-E<GD@96ET:&5R+B!4:&]S92!A\n"
	"M<F4@=&AI;F=S('EO=2!S964@;VX@=&AE('-T86=E(&]R('1H92!S8W)E96X@\n"
	"M;W(@=&AE('!R:6YT960@<&%G97,L('1H97D@;F5V97(@<F5A;&QY(&AA<'!E\n"
	"1;B!T;R!Y;W4@:6X@;&EF92X \n"
	"`\n"
	"end\n";

int main(int argc, char *argv[])
{
	std::string actual = uuencode(test, "file.txt");

	std::cout << actual;
	std::cout << (actual.compare(expected) == 0 ? "Correct" : "Incorrect") << '\n';
	return 0;
}

std::string uuencode(std::string input, std::string filename)
{
	std::string ret = "begin 644 " + filename + '\n';
	
	// make this into its own function

	std::vector<std::string> chunks_of_45;
	std::string counter_temp;
	unsigned counter = 0;

	for (unsigned i = 0; i < input.length(); ++i) {
		counter_temp.push_back(input[i]);
		counter++;
		if (counter == 45) {
			chunks_of_45.push_back(counter_temp);
			counter = 0;
			counter_temp.clear();
		}
		else if (i == input.length() - 1) {
			chunks_of_45.push_back(counter_temp);
		}
	}
	// end own function

	// make this its own function

	std::vector<std::string> ret_body;
	std::string substr_of_three = "";
	std::string ret_body_push_back = "";

	for (std::string s : chunks_of_45) {
		ret_body_push_back.push_back(static_cast<char>(32 + s.length()));
		if (s.length() % 3 != 0) {
			s.insert(s.end(), (3 - (s.length() % 3)), '\0');
		}
		for (unsigned offset = 0; offset < s.length(); offset += 3) {
			substr_of_three = s.substr(offset, 3);
			std::bitset<24> substr_of_three_in_bin((substr_of_three[0] << 16) | (substr_of_three[1] << 8) | substr_of_three[2]);
			for (unsigned i = 0; i < 24; i += 6) {
				std::bitset<6> substr_of_three_in_bin_groups_of_six(substr_of_three_in_bin.to_string(), i, 6);
				char c = substr_of_three_in_bin_groups_of_six.to_ulong() + 32;
				ret_body_push_back.push_back(c);
			}
		}
		ret_body_push_back.push_back('\n');
		ret_body.push_back(ret_body_push_back);
		ret_body_push_back.clear();
	}

	// end own function

	for (std::string s : ret_body) {
		ret += s;
	}

	ret += "`\nend\n";

	return ret;
}

/*
 *    Procedure
 *        - Write header
 *            - begin <mode> <file><newline>
 *            - mode = 644
 *            - file = filename
 *        - Write body
 *            - <length character><formatted characters><newline>
 *            - All lines have 45 bytes (60 characters) NOT INCLUDING LENGTH CHAR
 *			  - length character = actual byte count + ASCII character of 32
 *            - formatting characters:
 *                - start with 3 characters (3 bytes, 24 bits)
 *                - split into four 6-bit groupings
 *                - add 32
 *                - output ASCII equivalent
 *        - Write ending
 *            - `<newline>end<newline>
 */