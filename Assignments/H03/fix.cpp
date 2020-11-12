
/*
*   Allyson Warren
*   CMPS 2143
*   11/6/2020
*
*   Sort()
*   The function originally compared i to j+1 and determined which card rank was higher,
*   however, when it went to swap the two ranks, it would swap the card at j rather than the 
*   card at j+1 because of how the index was set up. Rather than have j be equal to i and then
*   compare i to j+1, it is better to already have j be 1 greater than i and loop through as such.
*   When a card at index j is higher than the card at index i, then the swap will switch properly.
*   This change keeps the sort a bubble sort but keeps i and j as their respective values rather than
*   looking at the indexes above or below.
*/
void Hand::Sort(){

    // Index "i" 
    for(int i=0;i<Size();i++){
        // Index "j"
        for(int j=i+1;j<Size();j++){
            //Comparing cards at position i and j 
            if(Cards[i]->rank > Cards[j]->rank){
                cout<<"swapping"<<endl;

                // standard swap 
                Card* temp = Cards[i];
                Cards[i] = Cards[j];
                Cards[j] = temp;
            }
        }
    }
}
