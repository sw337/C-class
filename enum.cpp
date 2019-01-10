#include <iostream>

using namespace std;

enum  MonthType {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC };

void  WriteOutName (MonthType);
MonthType GetMonth(string inStr);

main() {

    MonthType  month;
    string inStr;

    // Requires use of type cast to increment
    for  (month = JAN; month <= DEC; month = MonthType (month + 1)){
         WriteOutName (month);
    }
    cout << endl << endl;

    cout << "Enter a month: ";
    cin >> inStr;

    WriteOutName(GetMonth(inStr));

    return 0;
}

// Prints out month name
// Pre:  month is assigned
// Post: month name has been written out
void   WriteOutName ( /*  in  */  MonthType   month){
    switch (month) {
       	case JAN : cout << "January ";  break;
		case FEB : cout << "February "; break;
		case MAR : cout << "March ";	break;
		case APR : cout << "April ";	break;
 		case MAY : cout << "May ";	    break;
		case JUN : cout << "June ";	    break;
		case JUL : cout << "July ";	    break;
		case AUG : cout << "August ";	break;
		case SEP : cout << "September ";break;
		case OCT : cout << "October ";  break;
 		case NOV : cout << "November "; break;
		case DEC : cout << "December "; break;
		default : cout << "Invalid Month! "; break;
	}
}

// Returns enum MonthType corresponding to a given string
// Pre: inStr assigned a string
// Post: Return the MonthType enum matching the string or print
//       out invalid month message
MonthType GetMonth(string inStr){
    MonthType month;

    switch (toupper(inStr.at(0))) {
        case 'J':
            if (toupper(inStr.at(1)) == 'A')
                month = JAN;
            else if (toupper(inStr.at(2) == 'N'))
                month = JUN;
            else
                month = JUL;
            break;
        case 'F':
            month = FEB;
            break;
        case 'M':
            if (toupper(inStr.at(2)) == 'R')
                month = MAR;
            else
                month = MAY;
            break;
        case 'A':
            if (toupper(inStr.at(1)) == 'P')
                month = APR;
            else
                month = AUG;
            break;
        case 'S':
            month = SEP;
            break;
        case 'O':
            month = OCT;
            break;
        case 'N':
            month = NOV;
            break;
        case 'D':
            month = DEC;
            break;
        default:
            cout << "Invalid Month!\n";
            break;
    }

    return month;

}
