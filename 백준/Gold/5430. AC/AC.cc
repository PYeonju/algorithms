#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> temp;

    int T, N;
    cin >> T;

    string input, input2;
    bool isReverse = false;
    bool isBreak = false;
    
    while (T--)
    {
        temp.clear();
        isReverse = false;
        isBreak = false;

        cin >> input >> N >> input2;

        // 배열을 받아준다.
        // 이거 안받으면 문제 발생
        // 42같은 숫자는 4 / 2 이렇게 들어온다..
      	string number = "";
		for (auto c : input2)
		{
			if (c != '[' && c != ',' && c != ']')
				number += c;

			if (c == ']' || c == ',')
			{
                if(number!="")
				    temp.push_back(stoi(number));
				number = "";
			}
		}

        // 명령을 넣어준다.
        for (auto c : input)
        {
            if (c == 'D')
            {
                if (temp.empty())
                {
                    cout << "error\n";
                    isBreak = true;
                    break;
                }
                // 한번 뒤집혔다.
                if (isReverse)
                    temp.pop_back();
                else
                    temp.pop_front();
            }
            else
                isReverse = !isReverse;
        }
        
        if(isBreak)
            continue;
        
        // 출력 부분
        cout << "[";
        if (isReverse)
        {
            for (int i =temp.size()-1; 0 <= i; i--)
            {
                cout << temp[i];
                if (i != 0)
                    cout << ",";
            }
        }
        else
        {
            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i];
                if (i != temp.size() - 1)
                    cout << ",";
            }
        }
        cout << "]\n";
    }

    return 0;
}