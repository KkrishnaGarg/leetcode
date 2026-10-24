class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceReach = day(arriveAlice);
        int aliceDepart = day(leaveAlice);
        int bobReach = day(arriveBob);
        int bobDepart = day(leaveBob);
        if(aliceDepart==bobReach || bobDepart==aliceReach) return 1;
        else if(aliceDepart<bobReach || bobDepart<aliceReach) return 0;
        return (min(aliceDepart, bobDepart)-max(aliceReach, bobReach)+1);
    }
    int day(string s){
        int month = stoi(s.substr(0, 2));
        int date = stoi(s.substr(3, 2));
        switch(month){
            case 1:
                return date;
            case 2:
                return 31+date;
            case 3:
                return 59+date;
            case 4:
                return 90+date;
            case 5:
                return 120+date;
            case 6:
                return 151+date;
            case 7:
                return 181+date;
            case 8:
                return 212+date;
            case 9:
                return 243+date;
            case 10:
                return 273+date;
            case 11:
                return 304+date;
            case 12:
                return 334+date;
        }
        return -1;
    }
};