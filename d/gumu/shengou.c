
#include <ansi.h>
int get_object(object ob);
inherit ROOM;

void create()
{
     set("short", HIG"�"NOR);
     set("long", @LONG
�Ҵҵش������֣���ǰ����һ���(gou)����֪����Ȼ���ɽϪ�����ڣ�
��������ȥ·����ͷһ������������һ��ʯ��(shibei)��
LONG      
     );

     set("exits", ([
            "west" : __DIR__"shulin2",
        ]));    

        set("objects",([
                    __DIR__"npc/sun" : 1,
        ]));

     set("item_desc", ([
         "gou" : HIC"���������������Լ�к������ˣ�����ƺ�����Ʈ������������������˳�
Ȼ�����ĺ����ڣ�����Ȼ���������Խ�����һ��Ծ����(tiao)�µĳ嶯��\n"NOR,
         "shibei" : HIR"\t\t���ϻ�����Ĺ������Ī�룡\n"NOR,
          ]));

     set("outdoors", "��Ĺ");

     setup();
}
   
void init()
{
       add_action("do_jump", "tiao");
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int do_jump(string arg,object *obj)
{ 
        mapping fam;
        object me = this_player();
        object *inv = deep_inventory(me);        
       if ( !living(me) ) return 0; 
       if ( arg =="gou"){  
       if ((fam = me->query("family")) && fam["family_name"] == "ȫ���"){
          write(HIR"��ʦ��ѵ�������𣿣�\n"NOR);
          me->unconcious();
          me->move("/d/quanzhen/leizudian");
          return 1;
          }
        if ((fam = me->query("family")) && fam["family_name"] != "��Ĺ��")
          return notify_fail(HIR"\t\t��Ĺ�صأ�����Ī�룡\n"NOR);
        if (me->query("gender") == "����"){
          write(HIR"�����ֲ��в�Ů�Ķ����������Ĺ��\n"NOR);
          me->unconcious();
          me->move(__DIR__"lyy");
          return 1;
          }
     if ((int)me->query("per") < 23)
          return notify_fail(HIR"��������òǷ��, ���½�����Բ˫���ϱ�֮���Ρ�\n"NOR);
              if ((int)me->query_int() < 21)
          return notify_fail(HIR"������Ƿ��, ���½�����Բ˫���ϱ�֮���Ρ�\n"NOR);
        if (me->query_skill("literate", 1) < 30)
          return notify_fail(HIR"��Ķ���д��̫�ͣ����Ĺ�޷�����\n"NOR);
if (me->query_dex() < 18 )
          return notify_fail(HIR"����̫�ͣ�����ѧ���˹�ĹƮ��Ĺ���\n"NOR);
//      if (((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 25)){
        obj = filter_array(inv,(:get_object:));
        if(sizeof(obj)){
         write (HIR"�����͵͵�����˽�ȥ���������̫�࣬����һ����˩��ˤ���ڵء�\n"NOR);
         me->unconcious();
         me->move(__DIR__"shengou");
         return 1;
         }
        message("vision", me->name() + "�������ң�΢һ������ƾ���ݸ����࣬�¾�ƮƮ������������������ɽ���С�\n",
               environment(me), ({me})); 
        me->move(__DIR__"rukou");
        message_vision(HIY"$N���������������ǡ���ô����������ڹ�Ĺ���ǰ��\n"NOR, me);
        return 1;
        }
       return notify_fail("������������\n");
}

