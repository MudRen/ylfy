// shishi3.c

inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������һ�������ʯ�ң���֮������κ�һ������������������һ����
��������ľ�Ƴɵ����(shelf)�����л���һ��С��(bed)��
LONG
        );
       set("exits", ([
               "south" : __DIR__"shidong",
       ]));
        set("item_desc",([
        "shelf":"\n�����ȴ�յ�������һ����Ҳû�У��߽���ʱ��ֻ�����\n"
                "�������ˡ������ɡ����������ɡ���������ɡ�֮�����Ŀ��\n"
                "���������У����Ǹ��Ÿ��ɵ��书�ؼ���\n\n",
        ]));
        set("sleep_room", "1");
       setup();
}
void init()
{
        add_action("do_move","move");
        add_action("do_put","put");
}
int do_move(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="bed") return 0;
        message_vision("$N������С���ƿ����������澹Ȼ��һ������ͨ����\n",me);
        me->move(__DIR__"midao1");
        tell_object(me,"������һ���¡¡���������㶨��һ�����Լ��Ѿ�����������ͨ�����ˡ�\n");
     return 1; 
}
int do_put(string arg)
{
        object me,ob;
        me = this_player();

        if ( me->query_temp("kejuan") ) {
        if (!objectp(ob=present("bo juan",me)))
            return notify_fail("������û������������\n");
        if( arg=="juan in shelf" || arg=="bo juan in shelf") {
            message_vision("$N�����е�"+ob->query("name")+"�Ż���ܡ�\n",me);
            destruct(ob);
            message("vision","ͻȻ����¡��һ���������������̫�ã�����������\n",this_object());
            message("vision", "����Ҳ������ܵ��ڵ���\n",this_object());
            me->delete_temp("kejuan");
            me->set_temp("duxiaowu", 1);
            new(__DIR__"obj/bojuan-xia")->move(this_object());
        return 1;
            }
      } else return notify_fail("��ܶ����ˣ����ʲô����\n");
      return 0;
}
