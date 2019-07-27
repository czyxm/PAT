# Product of Polynomials
This time, you are supposed to find A¡ÁB where A and B are two polynomials.

### Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

$K N_1 a_{N1} N_2 a?_{N2} ... N?_K a_{NK}$
?? 

??where K is the number of nonzero terms in the polynomial, $N_i$ and $a_{?N?i}$ (i=1,2,?,K) are the exponents and coefficients, respectively. It is given that $1¡ÜK¡Ü10, 0¡ÜN_K<?<N_2<N_1¡Ü1000$.

### Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

### Sample Input:
```in
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```

### Sample Output:
```out
3 3 3.6 2 6.0 1 1.6
```

### Solution
Just multiply Poly1 with each items in Poly2 and then add the intermediate result to Poly.
For the add operation, I merge the two polys by comparing the first items in Poly1 and Poly2:
* Item1.exponent > Item2.exponent --> push Item1 into Poly
* Item1.exponent < Item2.exponent --> push Item2 into Poly
* Item1.exponent = Item2.exponent --> add Item1 and Item2 and push the result item into Poly if its coefficient not equals 0
* Deal with the left items in Poly1 or Poly2


```C++
#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

//Node structure for polynomial
typedef struct PolyNode
{
    int exponent;
    float coefficient;
}* PNode;

//Determine if the float number eaquals 0
inline bool isZero(float num)
{
    return (fabs(num) < 1E-6);
}

//Realse the node pointers in the vector
void release(vector<PNode> & poly);

/*@brief:Add two polynomials, actually merge them together
 *@param:vector poly1, poly2
 *@return:vector poly, the sum of poly1 and poly2
 */
vector<PNode> add(vector<PNode> & poly1, vector<PNode> & poly2);


int main()
{
    vector<PNode> poly, poly1, poly2;
    int k1, k2, exp;
    float coe;
    //Read poly1
    cin >> k1;
    for (int i = 1; i <= k1; i++)
    {
        PNode node = new PolyNode;
        cin >> node->exponent >> node->coefficient;
        poly1.push_back(node);
    }
    cin >> k2;
    for (int i = 1; i <= k2; i++)
    {
        //Reade an exponent and a coefficient each pass
        cin >> exp >> coe;
        //Multiply the poly1 by the single item and place the result in poly2
        for (int j = 0; j < k1; j++)
        {
            PNode node = new PolyNode;
            node->exponent = poly1[j]->exponent + exp;
            node->coefficient = poly1[j]->coefficient * coe;
            poly2.push_back(node);
        }
        //poly += poly2
        poly = add(poly, poly2);
    }
    //Display the information
    cout << poly.size();
    for (int i = 0; i < poly.size(); i++)
    {
        cout << " " << poly[i]->exponent << " " << fixed << setprecision(1) << poly[i]->coefficient;
    }
    //Release poly
    release(poly);

    return 0;
}

void release(vector<PNode> & poly)
{
    for (int i = 0; i < poly.size(); i++)
    {
        delete poly[i];
    }
    poly.clear();
}

vector<PNode> add(vector<PNode> & poly1, vector<PNode> & poly2)
{
    vector<PNode> poly;
    int i = 0, j = 0;
    //Merge when both the two polys are not void
    while (i < poly1.size() && j < poly2.size())
    {
        PNode node = new PolyNode;
        if (poly1[i]->exponent > poly2[j]->exponent)
        {
            node->exponent = poly1[i]->exponent;
            node->coefficient = poly1[i]->coefficient;
            i++;
        }
        else if (poly1[i]->exponent < poly2[j]->exponent)
        {
            node->exponent = poly2[j]->exponent;
            node->coefficient = poly2[j]->coefficient;
            j++;
        }
        else  //The same exponent
        {
            node->exponent = poly1[i]->exponent;
            node->coefficient = poly1[i]->coefficient + poly2[j]->coefficient;
            i++;
            j++;
            //If the value of result coeeficient eaquals 0, continue
            if (isZero(node->coefficient))
            {
                continue;
            }
        }
        poly.push_back(node);
    }
    //Deal with the left items in poly1
    while (i < poly1.size())
    {
        PNode node = new PolyNode;
        node->exponent = poly1[i]->exponent;
        node->coefficient = poly1[i]->coefficient;
        poly.push_back(node);
        i++;
    }
    //Deal with the left items in poly2
    while (j < poly2.size())
    {
        PNode node = new PolyNode;
        node->exponent = poly2[j]->exponent;
        node->coefficient = poly2[j]->coefficient;
        poly.push_back(node);
        j++;
    }
    //Release space
    release(poly1);
    release(poly2);
    return poly;
}
```