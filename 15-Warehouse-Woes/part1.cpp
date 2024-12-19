#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> board;
    vector<char> actions;
    int ox = -1, oy = -1;
    bool inBoard = true;
    string line;

    while (getline(cin, line))
    {
        if (line.empty())
        {
            inBoard = false;
            continue;
        }
        if (inBoard)
        {
            board.push_back(line);
        }
        else
        {
            for (char c : line)
            {
                actions.push_back(c);
            }
        }
    }

    for (int x = 0; x < board.size(); x++)
    {
        for (int y = 0; y < board[0].size(); y++)
        {
            if (board[x][y] == '@')
            {
                ox = x;
                oy = y;
            }
        }
    }

    int dx, dy, nx, ny, sx, sy;
    for (char a : actions)
    {
        if (a == '>')
        {
            dx = 0;
            dy = 1;
        }
        else if (a == '^')
        {
            dx = -1;
            dy = 0;
        }
        else if (a == '<')
        {
            dx = 0;
            dy = -1;
        }
        else if (a == 'v')
        {
            dx = 1;
            dy = 0;
        }
        nx = ox + dx;
        ny = oy + dy;

        if (board[nx][ny] == '.')
        {
            board[nx][ny] = '@';
            board[ox][oy] = '.';
            ox = nx;
            oy = ny;
        }
        else if (board[nx][ny] == 'O')
        {
            sx = nx;
            sy = ny;
            while (board[sx][sy] == 'O')
            {
                sx += dx;
                sy += dy;
            }
            if (board[sx][sy] == '#')
            {
                continue;
            }
            else
            {
                board[sx][sy] = 'O';
                board[nx][ny] = '@';
                board[ox][oy] = '.';
                ox = nx;
                oy = ny;
            }
        }
    }

    int res = 0;
    for (int x = 0; x < board.size(); x++)
    {
        for (int y = 0; y < board[0].size(); y++)
        {
            if (board[x][y] == 'O')
            {
                res += 100 * x + y;
            }
        }
    }

    cout << res << endl;

    return 0;
}