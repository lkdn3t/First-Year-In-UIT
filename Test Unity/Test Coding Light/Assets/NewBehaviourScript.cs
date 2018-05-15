using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour {
    public Light myLight;

    void Update() {
        if (Input.GetKeyDown("space")) {
            myLight.enabled = !myLight.enabled;
        }
    }
}