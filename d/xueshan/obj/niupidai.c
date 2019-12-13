// niupidai.c Å£Æ¤´ü
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name("Å£Æ¤´ü", ({"niu pidai", "pidai","dai","skin" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÓÃÀ´×°ËÖÓÍ²èµÄÅ£Æ¤´ü£¬É¢·¢³öµ­µ­µÄÈéÏã¡£\n");
                set("unit", "¸ö");
                set("value", 150);
                set("max_liquid", 10);
        } 
 
        set("liquid", ([ 
                "type": "suyou cha", 
                "name": "ËÖÓÍ²è", 
                "remaining": 10, 
                "drunk_supply": 20, 
        ])); 
}
int query_autoload() { return 1; }