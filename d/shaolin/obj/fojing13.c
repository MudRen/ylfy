
inherit ITEM;
void create()
{
    set_name("无名花", ({"hua", "wuming"}));
        set("unit", "朵");
    set("long", "这是一朵无名小花,花蕊虽小,却十分美丽。\n");
        setup();
}
int query_autoload() { return 1; }