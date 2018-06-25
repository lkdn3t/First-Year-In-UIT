using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Arrow: MonoBehaviour
{
    private BoxCollider2D collision;
    
    private void Start()
    {
        collision = GetComponent<BoxCollider2D>();    
    }

    private void Update()
    {
    }
}