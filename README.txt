Mahreen Abbasi - 300317493 
Katie Lonsway - 300315147


to compile: g++ -o testing Card.cpp CardFactory.cpp Deck.cpp Hand.cpp Player.cpp Table.cpp DiscardPile.cpp TradeArea.cpp main.cpp
to run: ./testing

description: this is the final project for CSI 2372, attached is the following files
Card.cpp
Card.h
CardFactory.cpp   
CardFactory.h
Chain.h
Deck.cpp
Deck.h
Hand.cpp
Hand.h
Main.cpp
NotEnoughCoins.h
Player.cpp
Player.h
Table.cpp
Table.h
DiscardPile.cpp
DiscardPile.h
TradeArea.cpp
TradeArea.h
README.txt

note, 
when player must play at their start of their turn and all chains are full, their first chain gets the new card.
a player can only chain up a card when they have an empty chian, it wouldn't make sense to play a card if you cant attach it to a chain
