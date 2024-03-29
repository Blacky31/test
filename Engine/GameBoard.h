#ifndef __GAME_BOARD__H
#define __GAME_BOARD__H

#include <boost/static_assert.hpp>
#include <boost/concept/assert.hpp>
#include <boost/foreach.hpp>
#include <boost/array.hpp>

namespace game { namespace engine {

template <unsigned int SIZE, 
	unsigned int BITS_PER_CELL_IN_CACHE, class CACHE_ROW_TYPE>
struct square_game_board
{
	BOOST_STATIC_ASSERT((SIZE * BITS_PER_CELL_IN_CACHE) <= (sizeof(CACHE_ROW_TYPE)*8));

	typedef CACHE_ROW_TYPE cache_row_type;

//	BOOST_CONCEPT_ASSERT((Assignable<cache_row_type>));
//	BOOST_CONCEPT_ASSERT((DefaultConstructible<cache_row_type>));
//	BOOST_CONCEPT_ASSERT((UnsignedInteger<cache_row_type>));

	typedef unsigned char cell_type;
	typedef cell_type player_type;

	enum cell_content
	{
		cell_empty = 0,
		cell_algorithm = 1,
		cell_opponent = 2,
		cell_empty_and_forbidden = 3
	};

	enum player
	{
		player_algorithm = 1,
		player_opponent = 2
	};

	typedef boost::array<cell_type, SIZE> row_type;
	typedef boost::array<row_type, SIZE> board_type;
	typedef boost::array<CACHE_ROW_TYPE, SIZE> cache_type;

	square_game_board(player_type current_player)
		: m_board(), 
          m_current_player(current_player),
          m_switched_player(switch_player(current_player))
	{}

	void generate_cache_key(cache_type& buffer) const
	{
		unsigned int x = 0;
		// !!!!!!!!!!?!?!?!?!?!?!?!?!?!?!?!?!?!?!?
		/*
		BOOST_FOREACH(row_type& row, m_board)
		{
			buffer[x] = 0;
			unsigned int y = 0;
			BOOST_FOREACH(cell_type cell, row)
			{
				buffer[x] |= (cell << (BITS_PER_CELL_IN_CACHE * y));
				y++;
			}
			++x;
		}
		 */
	}

	inline const cell_type& cell(const board_cell_coordinates& coordinates) const
	{
		return m_board[coordinates.m_y][coordinates.m_x];
	}

	inline cell_type& cell(const board_cell_coordinates& coordinates)
	{
		return m_board[coordinates.m_y][coordinates.m_x];
	}

	static inline player_type switch_player(player_type player)
	{
		return player == player_algorithm ? player_opponent : player_algorithm;
	}

    inline void switch_player()
    {
       player_type t =  m_current_player;
       m_current_player = m_switched_player;
       m_switched_player = t;
    }

public:
	board_type m_board;
	player_type m_current_player;
    player_type m_switched_player;
};

template <unsigned char MAX_PASS>
class pass_counter
{
public:
    inline bool is_pass_max() const
    {
        return m_passCounter == MAX_PASS;
    }

    inline void apply_pass()
    {
        ++m_passCounter;
    }
private:
    unsigned char m_passCounter;
};

}}  // engine, game

#endif // __GAME_BOARD__H