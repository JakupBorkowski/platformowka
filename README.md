# Platformówka

Gra będzie polegała na przejsciu kilku lvl-i. Aby ukończyć każdy z nich trzeba zdobyć odpowiednia liczbę punktów i dotrzeć do punktu(klocka) oznaczonego jako meta(myślałem, aby wykorzystać tutaj kolizję). Podczas przechodzenia każdego etapu gracz będzie musiał uważać na przeszkody(odmiennie wygladajacy obiekt odbierajacy graczowi jedno z jego żyć). Po utracie 3 nasz bochater powinien wrócić na pole startowe i rozpoczać określony lvl od pocztku. Gra będzie składał się z następujacych klas:
*cPostac - zawierajaca pole rysujace naszego bohatera oraz aktualizujaca jego punkty zycia
*cScena - do zawarcia zasad gry, narysowania planszy oraz zmieniania poszczególnych lvl-i
*cFizyka - dzięki niej umożliwię postaci skok
Ponadto klasy takie jak
*cProstokat
*cPrzeszkoda
i różne tego typu do narysowania planszy i przeszkod, meta i pole startowe prawdopodobnie również będa takimi elementami, lecz w innej klasie aby przez dynamic_cast móc badać z nimi kolizję.
