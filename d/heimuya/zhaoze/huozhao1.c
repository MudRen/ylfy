// Room: /d/heimuya/zhaoze/huozhao1.c
inherit ROOM;
int do_pull(string);
void create()
{
        set("short", "��Ĺ���");
        set("long", @LONG
��վ���������ˮ���Χ���յ��ںڵĹ�����«έ���㷢��һ
��ʮ�ֹ��������һ�����Ļ�����ˮ����ȼ�ա������������������
ʹ�˲����������뿪�˵صĸо���
LONG
);
        set("exits", ([ 
  "northeast" : __DIR__"huozhao",
  "east" : __DIR__"huozhao2",
]));
    set("objects", ([
        __DIR__"npc/ju-e" : 2,
]));
        setup();
}
void init()
{
        object me=this_player();

        if( interactive(me) ) {
            add_action("do_pull", "pull");
        if (random(me->query("kar"))<10){
            message_vision(RED "$N����ͻȻ�³�... ...\n" NOR,me);
            me->set_temp("drop_zhaoze",1);
            }
            call_out("hurn", 1, me);
        }
        
}
int do_pull(string arg)
{
    object ob;
    object me = this_player(); 

    if (!arg)
        return notify_fail("��Ҫ��˭��\n");

    if (!ob = present(arg,this_object()))
        return notify_fail("��Ҫ��˭��\n");

    if (me->query_temp("drop_zhaoze"))
        return notify_fail("���Լ��������ѱ��ˣ����������ˣ�\n");

    if (!ob->query_temp("drop_zhaoze"))
        return notify_fail(ob->name()+"����������\n");

    message_vision("�㳶ס$N���֣�ʹ����$n����������\n",me,ob);
    ob->delete_temp("drop_zhaoze");
    return 1;
}
int valid_leave(object me, string dir)
{
        if (dir=="south" && me->query_temp("drop_zhaoze")){
                message_vision("$Nʹ������һ�£���ͼ������̶.....\n",me);
                if (random(10)>5){   
                        me->apply_condition("scorpoin_poison",20);
                        tell_object(me,RED "\n��ͻȻ���ýű�ʲô��������һ��... ...\n" NOR);
                }
                if (random(me->query_skill("dodge",1))>600){
                        message_vision("$N����һ�ݣ�Ծ����̶��\n",me);
                        return 1;
                }else{
                        message_vision("$N���Խ��Խ�\n",me);
                        me->set_temp("die_for","�ݽ�������");
                        me->receive_wound("qi",200);
                       return notify_fail("���������󣬶������á�\n");
                }
        }
        return 1;
}
void hurn(object me)
{
        object ob;

        if( !me || environment(me) != this_object() ) return;
            me->apply_condition("fire_poison",50);            
        ob=me->query_temp("armor/cloth");
        if (!ob)        return;
        if ( ob->query("material")==("cloth") || ob->query("material")==("leather")){
            message_vision( HIR+"$N����"+ob->query("name")+HIR+"ͻȻ�Ż�ȼ��������$N��æ���ҵذ����������������ڵ��ϣ�\n"+NOR, me);
            ob->unequip();
            ob->move(this_object());
            ob->set("long", "����һ���յ��޷��ٴ���"+ob->query("name")+"��\n");
            ob->set("name","���Ƶ�"+ob->query("name"));
            ob->set("value",0);
            ob->set("armor_prop",0);
        }
}

