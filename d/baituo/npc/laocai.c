inherit NPC;
string inquiry_dao();
void create()
{
    set_name("�ϲ�", ({ "lao cai","cai" }) );
    set("gender", "����" );
    set("nickname","�ϲ�");
    set("age", 40);
    set("long", "һ�����������Ĺ����������տ����Ų�Ҳ�ܷ����Ƶġ�\n");
    set("shen_type",-1);
    set("combat_exp", 10000);
    set("str", 17);
    set("dex", 18);
    set("con", 18);
    set("int", 18);
    set("attitude", "friendly");
    set("inquiry" , ([
    "��" : (: inquiry_dao :),
    ]));
    setup();
    carry_object("/clone/cloth/cloth")->wear();
}
string inquiry_dao()
{
 object me=this_player();
 object ob;
 object *obj;
 int i;
 if (time()-me->query_temp("cai_dao")<60)
        return "�ϲĵ�����˵����ղŲ��������𣿻���Ҫ��\n";
 obj=deep_inventory(me);
 if (sizeof(obj))
 for (i=0;i<sizeof(obj);i++)
    if (obj[i]->id("cai dao"))
        return "�ϲĵ�����˵�������ϴ���һ�ѣ�����Ҫ��\n";
 ob=new("/d/baituo/obj/chaidao");
 ob->move(me);
 me->set_temp("cai_dao",time());
  return "�ϲĵݸ���һ�Ѳ񵶣�������˵��С�ı��ܣ�\n";
}
