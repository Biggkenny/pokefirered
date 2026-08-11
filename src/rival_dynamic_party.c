#include "global.h"
#include "pokemon.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/vars.h"
#include "event_data.h"
#include "battle.h"
#include "constants/items.h"
#include "constants/battle_ai.h"


struct TrainerMonItemCustomMoves sRivalDynamicParty[6];

void BuildRivalDynamicParty(void)
{
    u16 starter = VarGet(VAR_RIVAL_STARTER_SPECIES);
    u8 stage = VarGet(VAR_RIVAL_BATTLE_ID); // 0 = Oak's Lab, 1 = Route 22 Early, etc.

    switch (stage)
    {
    // --- Oak’s Lab battle ---
    case 0:
    default:
        sRivalDynamicParty[0] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 0,
            .lvl = 5,
            .species = starter,
            .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_NONE, MOVE_NONE},
        };
        break;

    // --- Route 22 Early ---
    case 1:
        sRivalDynamicParty[0] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 50,
            .lvl = 9,
            .species = SPECIES_PIDGEY,
            .moves = {MOVE_TACKLE, MOVE_SAND_ATTACK, MOVE_NONE, MOVE_NONE},
        };
        sRivalDynamicParty[1] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 50,
            .lvl = 9,
            .species = starter,
            .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_NONE, MOVE_NONE},
        };
        break;

    // --- Cerulean City ---
    case 2:
        sRivalDynamicParty[0] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 50,
            .lvl = 17,
            .species = SPECIES_PIDGEOTTO,
            .moves = {MOVE_TACKLE, MOVE_SAND_ATTACK, MOVE_GUST, MOVE_QUICK_ATTACK},
        };
        sRivalDynamicParty[1] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 50,
            .lvl = 16,
            .species = SPECIES_ABRA,
            .moves = {MOVE_TELEPORT, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        };
        sRivalDynamicParty[2] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 50,
            .lvl = 15,
            .species = SPECIES_RATTATA,
            .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_QUICK_ATTACK, MOVE_NONE},
        };
        sRivalDynamicParty[3] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 18,
            .species = starter, // still unevolved at this point
            .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_WITHDRAW, MOVE_WATER_GUN},
        };
        break;

    // --- S.S. Anne ---
    case 3:
        sRivalDynamicParty[0] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 50,
            .lvl = 19,
            .species = SPECIES_PIDGEOTTO,
            .moves = {MOVE_TACKLE, MOVE_SAND_ATTACK, MOVE_GUST, MOVE_QUICK_ATTACK},
        };
        sRivalDynamicParty[1] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 50,
            .lvl = 16,
            .species = SPECIES_RATICATE,
            .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_QUICK_ATTACK, MOVE_HYPER_FANG},
        };
        sRivalDynamicParty[2] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 50,
            .lvl = 18,
            .species = SPECIES_KADABRA,
            .moves = {MOVE_TELEPORT, MOVE_CONFUSION, MOVE_DISABLE, MOVE_NONE},
        };
        sRivalDynamicParty[3] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 20,
            .species = starter + 1, // evolved form
            .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_BITE, MOVE_WATER_GUN},
        };
        break;

        // --- Pokémon Tower ---
    case 4:
        sRivalDynamicParty[0] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 25,
            .species = SPECIES_PIDGEOTTO,
            .moves = {MOVE_WING_ATTACK, MOVE_SAND_ATTACK, MOVE_QUICK_ATTACK, MOVE_WHIRLWIND},
        };
        sRivalDynamicParty[1] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 23,
            .species = SPECIES_GROWLITHE,
            .moves = {MOVE_BITE, MOVE_ROAR, MOVE_EMBER, MOVE_LEER},
        };
        sRivalDynamicParty[2] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 22,
            .species = SPECIES_EXEGGCUTE,
            .moves = {MOVE_BARRAGE, MOVE_HYPNOSIS, MOVE_REFLECT, MOVE_NONE},
        };
        sRivalDynamicParty[3] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 20,
            .species = SPECIES_KADABRA,
            .moves = {MOVE_CONFUSION, MOVE_DISABLE, MOVE_KINESIS, MOVE_NONE},
        };
        sRivalDynamicParty[4] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 25,
            .species = starter + 1, // evolved starter
            .moves = {MOVE_BITE, MOVE_WATER_GUN, MOVE_WITHDRAW, MOVE_WHIRLPOOL},
        };
        break;

        // --- Silph Co. ---
    case 5:
        sRivalDynamicParty[0] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 37,
            .species = SPECIES_PIDGEOT,
            .moves = {MOVE_WING_ATTACK, MOVE_FEATHER_DANCE, MOVE_QUICK_ATTACK, MOVE_AERIAL_ACE},
        };
        sRivalDynamicParty[1] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 38,
            .species = SPECIES_GROWLITHE,
            .moves = {MOVE_FLAME_WHEEL, MOVE_TAKE_DOWN, MOVE_AGILITY, MOVE_LEER},
        };
        sRivalDynamicParty[2] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 35,
            .species = SPECIES_EXEGGCUTE,
            .moves = {MOVE_STUN_SPORE, MOVE_SLEEP_POWDER, MOVE_CONFUSION, MOVE_SOLAR_BEAM},
        };
        sRivalDynamicParty[3] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 100,
            .lvl = 35,
            .species = SPECIES_ALAKAZAM,
            .moves = {MOVE_PSYBEAM, MOVE_RECOVER, MOVE_FUTURE_SIGHT, MOVE_CALM_MIND},
        };
        sRivalDynamicParty[4] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 150,
            .lvl = 40,
            .species = starter + 2, // final evo
            .moves = {MOVE_BITE, MOVE_RAPID_SPIN, MOVE_PROTECT, MOVE_WATER_PULSE},
        };
        break;

    // --- Route 22 Late (Pre-League) ---
    case 6:
        sRivalDynamicParty[0] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 150,
            .lvl = 47,
            .species = SPECIES_PIDGEOT,
            .moves = {MOVE_FEATHER_DANCE, MOVE_WING_ATTACK, MOVE_GUST, MOVE_QUICK_ATTACK},
        };
        sRivalDynamicParty[1] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 150,
            .lvl = 45,
            .species = SPECIES_RHYHORN,
            .moves = {MOVE_TAKE_DOWN, MOVE_HORN_DRILL, MOVE_ROCK_BLAST, MOVE_FURY_ATTACK},
        };
        sRivalDynamicParty[2] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 150,
            .lvl = 45,
            .species = SPECIES_GROWLITHE,
            .moves = {MOVE_FLAME_WHEEL, MOVE_TAKE_DOWN, MOVE_LEER, MOVE_AGILITY},
        };
        sRivalDynamicParty[3] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 150,
            .lvl = 45,
            .species = SPECIES_EXEGGCUTE,
            .moves = {MOVE_SOLAR_BEAM, MOVE_SLEEP_POWDER, MOVE_POISON_POWDER, MOVE_STUN_SPORE},
        };
        sRivalDynamicParty[4] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 150,
            .lvl = 47,
            .species = SPECIES_ALAKAZAM,
            .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_FUTURE_SIGHT, MOVE_DISABLE},
        };
        sRivalDynamicParty[5] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 250,
            .lvl = 53,
            .species = starter + 2, // final form (e.g., Blastoise)
            .moves = {MOVE_WATER_GUN, MOVE_RAIN_DANCE, MOVE_BITE, MOVE_RAPID_SPIN},
        };
        break;
    // --- Champion (First Battle) ---
    case 7:
        sRivalDynamicParty[0] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 59, .species = SPECIES_PIDGEOT,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_AERIAL_ACE, MOVE_FEATHER_DANCE, MOVE_SAND_ATTACK, MOVE_WHIRLWIND},
        };
        sRivalDynamicParty[1] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 57, .species = SPECIES_ALAKAZAM,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_PSYCHIC, MOVE_FUTURE_SIGHT, MOVE_RECOVER, MOVE_REFLECT},
        };
        sRivalDynamicParty[2] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 59, .species = SPECIES_RHYDON,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_TAKE_DOWN, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB, MOVE_SCARY_FACE},
        };
        sRivalDynamicParty[3] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 59, .species = SPECIES_ARCANINE,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_EXTREME_SPEED, MOVE_FLAMETHROWER, MOVE_ROAR, MOVE_BITE},
        };
        sRivalDynamicParty[4] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 61, .species = SPECIES_EXEGGUTOR,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_GIGA_DRAIN, MOVE_EGG_BOMB, MOVE_SLEEP_POWDER, MOVE_LIGHT_SCREEN},
        };
        sRivalDynamicParty[5] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 63, .species = starter + 2,
            .heldItem = ITEM_SITRUS_BERRY,
            .moves = {MOVE_HYDRO_PUMP, MOVE_RAIN_DANCE, MOVE_SKULL_BASH, MOVE_BITE},
        };
        break;

        // --- Champion (Rematch) ---
    case 8:
        sRivalDynamicParty[0] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 72, .species = SPECIES_HERACROSS,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCK_TOMB},
        };
        sRivalDynamicParty[1] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 73, .species = SPECIES_ALAKAZAM,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_REFLECT},
        };
        sRivalDynamicParty[2] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 72, .species = SPECIES_TYRANITAR,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT, MOVE_AERIAL_ACE},
        };
        sRivalDynamicParty[3] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 73, .species = SPECIES_ARCANINE,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_EXTREME_SPEED, MOVE_OVERHEAT, MOVE_AERIAL_ACE, MOVE_IRON_TAIL},
        };
        sRivalDynamicParty[4] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 73, .species = SPECIES_EXEGGUTOR,
            .heldItem = ITEM_NONE,
            .moves = {MOVE_GIGA_DRAIN, MOVE_PSYCHIC, MOVE_SLEEP_POWDER, MOVE_LIGHT_SCREEN},
        };
        sRivalDynamicParty[5] = (struct TrainerMonItemCustomMoves)
        {
            .iv = 255, .lvl = 75, .species = starter + 2,
            .heldItem = ITEM_SITRUS_BERRY,
            .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_RAIN_DANCE},
        };
        break;
    }
}

