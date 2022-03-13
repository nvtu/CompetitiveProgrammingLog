#include <bits/stdc++.h>
using namespace std;


int main() {
    // freopen("test.txt", "r", stdin);
//     const string words[107] = { "AA", "AB", "AD", "AE", "AG", "AH", "AI", 
//         "AL", "AM", "AN", "AR", "AS", "AT", "AW", "AX", "AY", "BA", "BE", "BI", "BO", "BY",
// "ED", "EF", "EH", "EL", "EM", "EN", "ER", "ES", "ET", "EW", "EX",
// "FA", "FE", "GI", "GO", "HA", "HE", "HI", "HM", "HO", "ID", "IF", "IN", "IS", "IT", "JO", "KA", "KI",
// "LA", "LI", "LO", "MA", "ME", "MI", "MM", "MO", "MU", "MY", "NA", "NE", "NO", "NU",
// "OD", "OE", "OF", "OH", "OI", "OK", "OM", "ON", "OP", "OR", "OS", "OW", "OX", "OY",
// "PA", "PE", "PI", "PO", "QI", "RE", "SH", "SI", "SO", "TA", "TE", "TI", "TO", "UH", "UM", "UN", "UP", "US", "UT", "WE", "WO",
// "XI", "XU", "YA", "YE", "YO", "ZA" };
//     ios_base::sync_with_stdio(false);
//     string s;
//     cin >> s;
//     if (int(s.size()) == 1) cout << "YES" << endl;
//     else {
//         string ans = "NO";
//         for (int i=0; i<int(s.size()-1); i++) {
//             string subs = s.substr(i, 2);
//             bool ok = false;
//             for (int j=0; j<107; j++) {
//                 if (subs == words[j]) {
//                     ok = true;
//                     break;
//                 }
//             }
//             if (ok == false) {
//                 ans = "YES";
//                 break;
//             }
//         }
//         cout << ans << endl;

//     } 
    string s;
    cin >> s;
    if (s == "HELP" || s == "ANNA" || s == "MUG" || s == "SUM") cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}