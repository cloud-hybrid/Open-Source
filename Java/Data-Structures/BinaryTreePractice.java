// - Left child must always be less than parent.
// - Right child must always be greater than parent.
// - Leafs are the end-node of a branch.
// - Unbalanced Tree: Where a branch has a longer height than its mirror.
// - Random data normally doesn't cause an unbalances tree.
// - Ordered data typically causes an unbalanced tree.
// - Time complexity: O(log N).

public class BinaryTreePractice {

    Node root; // The parent node.

    public void addNode(int inputKey, String name) {
        Node newNode = new Node(inputKey, name);

        if (root == null){
            root = newNode;
        }
        else {
            Node iterativeNode = root; // Start at the root node.
            Node parent; // Place holder representing the iterative node's parent.

            while(true){
                parent = iterativeNode;

                if (inputKey < iterativeNode.key){
                    iterativeNode = iterativeNode.leftChild;

                    if (iterativeNode == null){
                        parent.leftChild = newNode;
                        break;
                    }
                }
                else {
                    iterativeNode = iterativeNode.rightChild;

                    if (iterativeNode == null){
                        parent.rightChild = newNode;
                        break;
                    }
                }
            }
        }
    }


    public static void main(String[] args) {

    }
}

class Node {
    int key;
    String name;

    Node leftChild; // Child Nodes can be left null.
    Node rightChild;

    Node(int inputKey, String inputName){
        key = inputKey;
        name = inputName;
    }

    public String toString(){
        return name + ": " + key;
    }
}
