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