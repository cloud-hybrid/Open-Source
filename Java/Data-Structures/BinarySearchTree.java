import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class BinarySearchTree<T> implements Set<T>
{
    private BinaryNode<T> root = null;
    private Comparator<? super T> comparator;

    public BinarySearchTree(Comparator<? super T> comparator)
    {
        this.comparator = comparator;
    }

    public Iterator<T> iterator()
    {
        if (root == null)
        {
            return new Iterator<T>()
            {
                public boolean hasNext() { return false; }
                public T next() { throw new NoSuchElementException(); }
            };
        }
        else
        {
            return root.iterator();
        }
    }

    public int size()
    {
        return root == null ? 0 : root.size();
    }

    private T add(T item, BinaryNode<T> root)
    {
        if (this.comparator.compare(item, root.getData()) < 0)
        {
            // Item is less than root:
            // add to left subtree
            if (root.getLeft() == null)
            {
                // Base case: opening for a left child
                BinaryNode<T> newNode = new BinaryNode<T>();
                newNode.setData(item);
                root.setLeft(newNode);
                return item;
            }
            else
            {
                // Recursively add to left subtree
                return add(item, root.getLeft());
            }
        }
        else if (this.comparator.compare(item, root.getData()) > 0)
        {
            // Item is less than root:
            // add to right subtree
            if (root.getRight() == null)
            {
                // Base case: opening for a right child
                BinaryNode<T> newNode = new BinaryNode<T>();
                newNode.setData(item);
                root.setRight(newNode);
                return item;
            }
            else
            {
                // Recursively add to right subtree
                return add(item, root.getRight());
            }
        }

        // If elements are equal (duplicate), the item is already in the tree
        return root.getData();
    }

    public T add(T item)
    {
        if (this.root == null)
        {
            this.root = new BinaryNode<T>();
            this.root.setData(item);
            return item;
        }
        else
        {
            return add(item, this.root);
        }
    }

    private T getMatch(T item, BinaryNode<T> root)
    {
        if (this.comparator.compare(item, root.getData()) < 0)
        {
            // Item is less than root:
            // search in left subtree
            if (root.getLeft() == null)
            {
                // Base case: item not found
                return null;
            }
            else
            {
                // Recursively search in left subtree
                return getMatch(item, root.getLeft());
            }
        }
        else if (this.comparator.compare(item, root.getData()) > 0)
        {
            // Item is less than root:
            // search in right subtree
            if (root.getRight() == null)
            {
                // Base case: item not found
                return null;
            }
            else
            {
                // Recursively search in right subtree
                return getMatch(item, root.getRight());
            }
        }
        else
        {
            // Base case: item found
            return root.getData();
        }
    }

    public T getMatch(T item)
    {
        return this.root == null ? null : getMatch(item, this.root);
    }

    public T remove(T item)
    {
        throw new UnsupportedOperationException();
    }

    public String toString()
    {
        return "[" + (root == null ? "" : root.inOrder(", ")) + "]";
    }

    public static void main(String[] args)
    {
        BinarySearchTree<Double> tree =
            new BinarySearchTree<Double>(Comparator.naturalOrder());
        for (int i = 0; i < 100; i++)
        {
            tree.add(Math.random());
        }

        System.out.println(tree);
    }
}
