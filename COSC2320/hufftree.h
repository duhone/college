
typedef struct hufftree  *HuffTree;
struct hufftree
 {
   char ch;
   int freq;
   HuffTree left;
   HuffTree right;
 };

HuffTree NewHuffTree(char ch,int freq);
HuffTree JoinHuffTrees(HuffTree t1,HuffTree t2);
void OutputHuffCodes(HuffTree t);
