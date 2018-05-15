using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//Khi Bird đi qua trigger ở vùng trống sau cột (tăng điểm)
public class Column : MonoBehaviour {
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.GetComponent<Bird>() != null)
            GameControl.instance.BirdScored();
    }
}