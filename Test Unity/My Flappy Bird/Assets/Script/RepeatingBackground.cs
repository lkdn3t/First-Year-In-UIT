using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RepeatingBackground : MonoBehaviour
{
    private BoxCollider2D groundCollider;
    private float groundHorizontalLength;

    //Định khung hình của background (lấy mặt đất làm chuẩn, Sky là kéo theo)
    //Lấy độ dài của khung hình background
    void Start()
    {
        groundCollider = GetComponent<BoxCollider2D>();
        groundHorizontalLength = groundCollider.size.x;
    }

    // Cập nhật liên tục lại background khi di chuyển hết
    void Update()
    {
        if (transform.position.x < -groundHorizontalLength)
        {
            RepositionBackground();
        }
    }

    //Đặt lại khung hình mới sau khi đi hết 1 khung
    //Cụ thể: Double 1 map mới ngay sau đó (map 2), sau khi đi hết map1 thì dời map1 ra sau map2
    //Tương tự với map2, cứ thế tạo thành một vòng lặp vô tận cho background
    private void RepositionBackground()
    {
        Vector2 GroundOffset = new Vector2(groundHorizontalLength * 2f, 0);
        transform.position = (Vector2)transform.position + GroundOffset;
    }
}
