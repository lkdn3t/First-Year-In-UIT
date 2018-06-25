using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoxCounter : MonoBehaviour
{
    private BoxCollider2D bcld;
    static public int counter = 0;
    
    void Start()
    {
        bcld = GetComponent<BoxCollider2D>();
    }
}