/*
    File: move.h

    Move utils and move history utils.
    Assumes that a history list and the board it's used with are consistent.

    Boardhistory:
    A move event consists of a series of board changes and a "move done",
    namely BoardChange.where == (boardsize = move_done), which is pushed last for each move event.

    Author: Ken Rouwas
    Date 2017-09-14
*/

#pragma once

#include <list>
#include <vector>

#include "board.h"

namespace Chess {

    const size_t move_done = board_size;

    struct Move {
        ssize_t from, to;
        Move(ssize_t, ssize_t);
        Move();
    };

    struct BoardChange {
        size_t where;
        Square old_square;
    };

    using Boardhistory = std::list<BoardChange>;
    using MoveSet = std::vector<Move>;

    void undo_move(Board&, Boardhistory&);

    /* Castling is identified by king move to its castling destination if permitted.
       Pawn promotion move deduced.
       All other moves are unconditional moves.
    */
    void do_move(Move, Board&, Boardhistory&, Piece pawn_promotion = Piece::queen);

    MoveSet valid_moves(Board&, Color turn); // This is the move generator

}
