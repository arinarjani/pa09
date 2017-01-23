# pa09
CSN: CS135 Homeowrk Assignment

Write	a	program	that	shuffles	and	deals	a	hand	of	cards	from	a	full	deck.	The	deck	of	cards	is	represented	by	a	vector	of	52	elements.	Each	element	in	the	vector	is	a	structure	for	one	card,	as	shown	below.	(Updated	to	resemble	the	syntax shown	in	your	book.	However,	you	may	still	use	the	typedef	approach	shown	in	the	original	assignment.)	

	struct Card {        
    string suit;   ///< Clubs, Diamonds, Hearts, Spades         
    int    value;  ///< Ace, Deuce, 3..10, Jack, Queen, King }; 
 
 typedef vector<Card> Deck; 
 typedef Deck Hand; 
 
Write	the	following:	
  1. A	function	that	initializes	a	new	Deck	of	Cards.	All	values	should	be	in	order	by	suit.	(Hint:	Use	nested	loops	to	initialize	each	new	Card	before	being	added	to	the	Deck.)	
  2. A	function	that	neatly	prints	a	Deck	of	Cards.	
  3. A	function	that	randomly	shuffles	a	Deck	of	Cards.	(Hint:	Generate	a	random	number	in	the	range	0..51	and	exchange	the	current	card	with	the	card	in	the	random	position.)	
  4. A	function	that	deals	a	Hand	of 5	Cards.	As	each	card	is	dealt,	it	should	be	removed	from	the	Deck.	
  5. A	driver	program	that	initializes	a	new	Deck	of	Cards,	shuffles	them,	then	deals	and	prints	a	Hand.	
