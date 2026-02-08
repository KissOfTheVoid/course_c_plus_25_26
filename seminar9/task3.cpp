/*
    Works with ncurses.h, unistd.h, vector, cstdlib, ctime libraries
    Dino Game (with cat instead of dino)
*/


#include <ncurses.h>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class DinoRunner {
private:
    int score = 0;
    int dino_y = 0;
    std::vector<int> obstacles;
    bool game_over = false;
    bool jumping = false;
    
public:
    void setup() {
        initscr();
        noecho();
        curs_set(0);
        keypad(stdscr, TRUE);
        timeout(100);
        srand(time(NULL));
    }
    
    void draw() {
        clear();
        mvprintw(0, 0, "DINO RUNNER    Score: %d    [SPACE to JUMP]", score);
        mvprintw(2, 0, "Press q to quit");
        for (int x = 0; x < COLS; x++) {
            mvaddch(LINES-3, x, '_');
        }
        int dino_x = 5;
        if (jumping) {
            mvprintw(LINES-5, dino_x, "  /\\__/\\  ");
            mvprintw(LINES-4, dino_x, " (=^.^=) ");
        } else {
            mvprintw(LINES-4, dino_x, " /\\__/\\  ");
            mvprintw(LINES-3, dino_x, " (=0.0=) ");
        }
        for (int obs_x : obstacles) {
            if (obs_x >= 0 && obs_x < COLS) {
                mvaddch(LINES-4, obs_x, '|');
                mvaddch(LINES-3, obs_x, '|');
            }
        }
        if (game_over) {
            mvprintw(LINES/2, COLS/2-10, "GAME OVER! Final Score: %d", score);
            mvprintw(LINES/2+2, COLS/2-8, "Press q to quit");
        }
        refresh();
    }
    
    void update() {
        if (game_over) return;
        if (jumping) {
            dino_y++;
            if (dino_y >= 8) {
                jumping = false;
                dino_y = 0;
            }
        }
        for (int& obs : obstacles) obs -= 2;
        
        if (rand() % 20 < 2 || obstacles.empty()) {
            obstacles.push_back(COLS-1);
        }
        
        obstacles.erase(
            std::remove_if(obstacles.begin(), obstacles.end(),
                [](int x){ return x < -5; }),
            obstacles.end()
        );
        
        for (int obs_x : obstacles) {
            if (obs_x >= 3 && obs_x <= 12 && !jumping) {
                game_over = true;
                break;
            }
        }
        
        score++;
        usleep(120000);
    }
    
    void input() {
        int ch = getch();
        switch(ch) {
            case ' ': if (!jumping) jumping = true; break;
            case 'q': case 'Q': game_over = true; break;
        }
    }
    
    void run() {
        setup();
        while (!game_over) {
            input();
            update();
            draw();
        }
        
        mvprintw(LINES-1, 0, "Press any key to exit...");
        getch();
        endwin();
    }
};

int main() {
    DinoRunner game;
    game.run();
    /*
    the output is really fun! Just try it!
    */
    return 0;
}
