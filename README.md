# Platformówka

Gra będzie polegała na przejsciu kilku lvl-i. Aby ukończyć każdy z nich trzeba zdobyć odpowiednia liczbę punktów i dotrzeć do punktu(klocka) oznaczonego jako meta(myślałem, aby wykorzystać tutaj kolizję). Podczas przechodzenia każdego etapu gracz będzie musiał uważać na przeszkody(odmiennie wygladajacy obiekt odbierajacy graczowi jedno z jego żyć), w miarę możliwości postaram się, aby dodać również ruchome przeszkody. Po utracie 3 nasz bochater powinien wrócić na pole startowe i rozpoczać określony lvl od pocztku. Gra będzie składał się z następujacych klas:

1.**cPostac** - zawierajaca pole rysujace naszego bohatera oraz aktualizujaca jego punkty zycia

2.**cScena** - do zawarcia zasad gry, narysowania planszy oraz zmieniania poszczególnych lvl-i

3.**cFizyka** - dzięki niej umożliwię postaci skok

Ponadto klasy takie jak:

1.**cProstokat**

2.**cPrzeszkoda**

3.**cFigura**(zawiera cProstokat, cOkrag oraz inne potrzebne prymitywy geometryczne)

4.**cOkrag**

i różne tego typu do narysowania planszy i przeszkod, meta i pole startowe prawdopodobnie również będa takimi elementami, lecz w innej klasie aby przez dynamic_cast móc badać z nimi kolizję.


**STEROWANIE:**

Pierwotnie zakładam, sterowanie będzie odbywało się za pomocą przycisków w(skok), a(ruch w lewo), d(ruch w prawo).

**GRAFIKA:**

Jeżeli chodzi o grafikę nie mam pomysłu jak to rozwiązać, ale znalezienie dodatkowej biblioteki powinno rozwiązać ten problem.

**Gra na której się wzoruje.**
https://www.youtube.com/watch?v=2t0wjukqtdE
