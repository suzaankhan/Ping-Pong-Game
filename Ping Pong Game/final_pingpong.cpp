#include<graphics.h>
int width = 900, height = 500;
//speed_x = 4, speed_y = 4, page = 0, change = 4
/*speed_x = 4;
speed_y = 4;
change = 4;*/
void maingame()
{
    int x = 200, y = 200, r = 20, speed_x = 5, speed_y = 5, page = 0, change = 5, bar_change = 0, bar_change_l = 0;
    int x1_left = 0, y1_left = 200, x2_left = 25, y2_left = 300, l_barspd = 3;
    int x1_right = 875, y1_right = 200, x2_right = 900, y2_right = 300, r_barspd = 3;
    int t=1;
    while(t)
    {
        setcolor(WHITE);
        line(450,0,450,500);
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        circle(x , y, r);
        floodfill(x, y, WHITE);
        bar(x1_left, y1_left, x2_left, y2_left);
        bar(x1_right, y1_right, x2_right, y2_right);
        if(y >= height - 15)
        {
            speed_y -= change;
        }
        // BOUNCING LOGIC
        if(y >= y1_right-5 && y <= y2_right+5 && x >= x1_right - 20)
        {
            speed_x -= change;
        }
        if(y <= 0+8)
        {
            speed_y += change;
        }
        if(y >= y1_left-5 && y <= y2_left+5 && x <= x1_left + 40)
        {
            speed_x += change;
        }
        // LEFT BAR UP DOWN LOGIC
        if(GetAsyncKeyState(VK_UP))
        {
            bar_change = -3;
        }
        if(y1_right < 0)
        {
            bar_change = 0;
        }

        if(GetAsyncKeyState(VK_DOWN))
        {
            bar_change = 3;
        }
        if(y2_right >= height)
        {
            bar_change = 0;
            if(GetAsyncKeyState(VK_UP))
            {
                bar_change = -3;
            }
        }
        //FOR LEFT BAR MOVING LOGIC
        if(GetAsyncKeyState('A'))
        {
            bar_change_l = -3;
        }
        if(y1_left < 0)
        {
            bar_change_l = 0;
        }

        if(GetAsyncKeyState('Z'))
        {
            bar_change_l = 3;
        }
        if(y2_left >= height)
        {
            bar_change_l = 0;
            if(GetAsyncKeyState('A'))
            {
            bar_change_l = -3;
            }
        }
        // GAME OVER CONDITION
        if(x+20 > width || x-20 < 0)
        {
            speed_x = 0;
            speed_y = 0;
            l_barspd = 0;
            r_barspd = 0;
            bar_change = 0;
            bar_change_l = 0;
            settextstyle(BOLD_FONT, HORIZ_DIR, 5);
            outtextxy(335,230,"GAME OVER");
            outtextxy(170,270,"PRESS SPACE TO CONTINUE");
            if(GetAsyncKeyState(VK_SPACE))
            {
                maingame();
            }
        }
        x += speed_x;
        y += speed_y;

        y1_right += bar_change;
        y2_right += bar_change;

        y1_left += bar_change_l;
        y2_left += bar_change_l;

        delay(5);
        page = 1 - page;
    }
}

int main()
{
    initwindow(width, height, "Bounce Ball", 150, 150);
    setbkcolor(DARKGRAY);
    maingame();
    getch();
    closegraph();
    return 0;
}

