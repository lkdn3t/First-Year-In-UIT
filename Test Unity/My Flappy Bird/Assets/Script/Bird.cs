using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bird : MonoBehaviour
{
    public float UpForce = 200f;
    public bool isDead = false;
    private Rigidbody2D rgbd;
    private Animator anim;

    //Bắt đầu game: set xác định vị trí và chim
	void Start ()
    {
        rgbd = GetComponent<Rigidbody2D>();
        anim = GetComponent<Animator>();
	}
	
	// Update được gọi liên tục theo từng frame để cập nhật trạng thái
	void Update ()
    {
        //Khi chim chưa chết
        if (!isDead)
        {
            //Khi nhấn chuột: cập nhật lại trạng thái và tăng độ cao
            if (Input.GetKeyDown("space"))
            {
                rgbd.velocity = Vector2.zero;
                rgbd.AddForce(new Vector2(0, UpForce));
                anim.SetTrigger("Flap");
            }
        }	
	}

    //Khi va chạm vào vật thể: set chim đứng yên và đặt chim chết
    void OnCollisionEnter2D()
    {
        rgbd.velocity = Vector2.zero;
        isDead = true;
        anim.SetTrigger("Die");
        GameControl.instance.BirdDied();
    }
}