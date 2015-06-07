#include <SDL2/SDL.h>
#include <stdio.h>
#include <unordered_map>
#include <memory>

class FSimulation {
public:
    virtual bool update(double dt) = 0;
};


class FDraw {
public:
    virtual bool draw(SDL_Renderer *ren) = 0;
};

class CEntity {
public:
    SDL_Rect bBox;

    FSimulation *sim;
    FDraw *draw;

    virtual bool init() = 0;
};


class CObjectManager {

    std::unordered_map<std::string, std::shared_ptr<CEntity>> entities;

public:
    bool registerNew(const std::string name, std::shared_ptr<CEntity> obj) {
        entities.insert(std::pair<std::string, std::shared_ptr<CEntity>>(name, obj));
        return true;
    }

    std::shared_ptr<CEntity> getEntityByName(const std::string name) {
        return entities.find(name)->second;
    }
};


class CGrowingBox: public CEntity {

    class FGrowingBoxDraw: public FDraw {
        bool draw(SDL_Renderer *ren) {
            uint32_t mod = SDL_GetTicks() / 10;

            SDL_Rect bBox;
            bBox.x = 0;
            bBox.y = 0;
            bBox.w = 50 + mod;
            bBox.h = 50 + mod;

            SDL_SetRenderDrawColor(ren, 0, 255, 0, 255);
            SDL_RenderDrawRect(ren, &bBox);
            return true;
        };
    };

public:
    CGrowingBox() {
        draw = new FGrowingBoxDraw();
    };

    bool init () {
        return true;
    };
};




class CGame {
private:
        SDL_Window *mainWindow;
        SDL_Renderer *mainRenderer;

        uint32_t lastTime;
        uint32_t dt;

        CObjectManager *manager = new CObjectManager();

    public:
        bool init();
        bool isStopping();
        bool run();
        ~CGame();
};








