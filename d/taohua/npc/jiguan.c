//jiguan.c ������
inherit NPC;
void create()
{
        set_name("������", ({"jiguan ren", "ren"}));
        set("gender", "����");
        set("age", 100);
        set("long","��Щ�����˶��ǻ�ҩʦ������Ƶģ�ר��Ϊ������������á�\n");
        set("attitude", "peaceful");
        set("str", 10);
        set("int", 10);
        set("con", 10);
        set("dex", 10);
        set("qi", 100000);
    set("no_suck",1);           // ������jing,neili
        set("max_qi", 100000);
        set("jing", 100000);
        set("max_jing", 100000);
        set("combat_exp", 2000);
        setup();
}
