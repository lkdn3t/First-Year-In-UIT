using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScrollingObject : MonoBehaviour
{
    private Rigidbody2D rgbd;

    void Start()
    {
        rgbd = GetComponent<Rigidbody2D>();
        rgbd.velocity = new Vector2(GameControl.instance.ScrollSpeed, 0);
    }

    void Update()
    {
        if (GameControl.instance.GameOver == true)
        {
            rgbd.velocity = Vector2.zero;
        }
    }
}