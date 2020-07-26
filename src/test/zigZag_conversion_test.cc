#include "../solution/zigZag_conversion.h"

struct Arg {
  string s;
  int numRows;
};

const vector<Arg> testSet = {
    Arg{ .s="PAYPALISHIRING", .numRows=3 },
//    Arg{ .s="PAYPALISHIRING", .numRows=4 },
//    Arg{ .s="A", .numRows=2 },
//    Arg{ .s="ABCDE", .numRows=3 },
//    Arg{ .s="qiinggopdgterivtxaviyspdbjecqicislxyrlpwtjaktygsadayvpdyajaqtdylovjhgydbjfoefuwfxwduniunrvfkydvoygvghykqfyvlstqrqwnfejvyeaieegsempntnxmvxjgrcwkuuzazivznxhtbpmicdxxrwjotsumvqwpnvrodonsmumpmazodwlwuxknpezmxxeksvyymlqyheptepjilxeiurxlvzasweerbcpnphnzmdssueahbhpvynivmiqioubqzqfqavpmaieumhbpqrkqgulsdbcryejzwrpwofioppkbylsoecekwrebvhvtleshxheloobdflgdxyrdcvobnsckbxdoexybgcnvsoaychbbfveksulhpnrqlwfptdsahfxbwxbyefbmafwsahcpwthjqmajrtlaykcwidwoixcifadfjfwgafrquscllpmlaoiktgacgdmlfpsrwozxvqppirbthphjfrtyxtadypogegxdwwasmpjxjmsqbzbgquhopjtqykwfqtippkjdbsakfvciudplzybphwfggblzwvqnfzqitttaoxjkbaxcyarfxynfzygxvwkaxdjtyetobeyeewheyamxzzdaajyvikyfnjalnubqaaxfyglwgxuhxzizkiussuaidavswxjxziezopvwnrgmsqndyjvsexahyyauxltwvxvlnshcmpqefdjdmhyqeaaeyczvnstksovfhehvuzzzclfqsdjwdjbelczawtmojhtslcnfdpffakysphqssrwfvyhstt", .numRows=700 },
};

void zigZag_conversion_test() {
//  batch_invoke(testSet, ZigZagConversion::convert);
  batch_invoke(testSet, ZigZagConversionBest::convert);
}
