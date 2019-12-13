#include <ansi.h> 

inherit __DIR__"smithh.c"; 

void create()
{
        set_name("Ìú½³", ({ "tiejiang", "smith" }));
        set("title", "¼×ëÐµêÀÏ°å");
        set("shen_type", 1);
        set("gender", "ÄÐÐÔ" );
        set("age", 33);
        set("long", "Ìú½³ÕýÓÃÌúÇ¯¼Ð×¡Ò»¿éºìÈÈµÄÌú¿é·Å½øÂ¯ÖÐ¡£\n");

        set("combat_exp", 400);
        set("attitude", "friendly");
        set("vendor_goods",({
                   "/clone/armor/armor",
                   "/d/city/obj/beixin",
                   "/clone/armor/jinsijia",
        }));

        setup();

        carry_object("/clone/cloth/cloth")->wear();
}
