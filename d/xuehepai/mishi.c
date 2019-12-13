inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","Ѫ������");
        set("long",@LONG
�Ӷ�����̤�������ǰһ��:�����ұ���д�ż���С��(zi)��д
��������������ޱȡ��ֻ�����һ�������ݡ����ұڴ��м���
�֣���ʱ�Ѿã�ģ�������ˡ�������һʯ����������ϥ����һ���ˡ���
����֮������Ȼ��ˮ�ף����м������������С����������ܳ�ȥ��
LONG );
        set("class","Ѫ����");
        set("exits",([
                  "out" : __DIR__"jiliu",
                  "west" : __DIR__"chucangshi",
        ]));
/*
       set("item_desc"��([
                "zi"         : @LONG
����Ѫ���ɾ��У��Ȱ����࣬���˴���
��Ϊ���ɵ�ʮ�������š���������ͬ�֡�
LONG
��
        ]));
*/
//        set("no_clean_up"�� 0);
        setup();
}

void init()
{

        add_action("do_kan","qiao");
        add_action("do_wa","wa");
        add_action("do_ketou","kneel");
        add_action("do_mai","mai");
}

int do_kan(string arg)
{
           object me;
           string temp;
           
           me=this_player();
           temp=read_file("/log/MISHI",1,1);
           if ((!arg) && (arg!="chuang") && (arg!="ʯ��") && (arg!="zi"))
           return notify_fail("��Ҫ��ʲô��\n");

           if ((arg=="chuang") || (arg=="ʯ��") )
           {
                 if (this_player()->query_skill("longmen-shengong",1))
                         return notify_fail("�㲻Ҫ̫̰���ˡ�\n");

                if (query("opened")) return notify_fail("ʯ���Ͽտ���Ҳ��\n");
                tell_object(me,"ֻ��ʯ��������һ������ģ�������ӡ���\n");
                tell_object(me,"ϥ��������ָ����ָ���ұ��ϵ�С�֡�\n");
                me->set_temp("look-chuang",1);
                return 1;
           }

           if (arg=="zi")
           {
                if (!(me->query_temp("look-chuang")))
                      return notify_fail("û�²�Ҫ͵�����˵Ķ�����\n");
                tell_object(me,"����Ѫ���ɾ��У��Ȱ����࣬���˴���\n");
                tell_object(me,"��Ϊ���ɵ�ʮ�������š���������ͬ�֡�\n");
                me->set_temp("look-zi",1);
                return 1;
           }
           return 0;
}

int do_wa(string arg)
{
            object me;

            me=this_player();

            if (me->query_temp("digg"))
                   return notify_fail("���Ѿ�����һ�����ˡ�\n");
            if(!(me->query_temp("look-zi")))
            return notify_fail("�����˼ҵĵط���������\n");
            if (!arg && arg!="west" && arg!="east")
                   return notify_fail("���ߺ����߶���һ��յأ����ߵ���΢��һ�㡣��Ҫ���ıߣ�\n");

            if (arg=="west")
            {
                  message_vision("$N����һ�������ʯͷ�������ߵĿյ�������������\n",me);
                  message_vision("��һ�����$N������һ������\n",me);

                  me->set_temp("digg",1);
                  return 1;
            }
            if (arg=="east")
            {
                 message_vision("$N����һ�������ʯͷ���ڶ��ߵĿյ�������������\n",me);
                 message_vision("ͻȻ���������һö��������������ʺ�\n",me);
                  me->delete_temp("look-chuang");
                  me->delete_temp("zi");
                  me->die();
            }
            return 0;
}

int do_mai(string arg)
{
           object me;
           object ob;
           mapping fam;
           string temp;

           me=this_player();
           fam=me->query("family");
           temp=read_file("/log/MISHI",1,1);

           if (!arg && arg!="yiti" && arg!="����")
                 return notify_fail("��Ҫ��ʲô������\n");
           if (arg=="yiti" || arg=="����")
           {
                if(!(me->query_temp("ketou")))
                        return notify_fail("��û��ͷ�Ͱᶯ���壬����̫�ð� ?\n");
                message_vision("$N��ǰ����������������ƶ����塣\n",me);
                message_vision("ͻȻ��$N�����Լ����ֱ�ճ���������ˣ�һ�������������г��˹�����\n",me);
                message("chat",HIM"��������"HIC"��˵"+me->query("name")+"�ҵ��������ص����塣�õ���Ѫ�������Ͳ��ٺô���\n"NOR,users());
                me->add("max_neili",100);
               //if (me->query("max_neili")>(me->query("con")*me->query_skill("force",1)+1) )
               // me->set("max_neili",(me->query("con")*me->query_skill("force",1)+1));
                me->delete_temp("look-chuang");
                me->delete_temp("look-zi");
                me->delete_temp("ketou");
                me->delete_temp("digg");
                if (!temp)
                me->set("title","Ѫ���ɵ�ʮ����"HIR"����"NOR);
                if (!fam || fam["family_name"]!="Ѫ����")  {
                        fam["family_name"]="Ѫ����";
                        me->set("family",fam);
                }
                message_vision("ͻȻ�ο�֪����ð�˳���������Ц��������ʦֶ����Ѫ���������������㱣�ܰɡ�\n",me);
                me->unconcious();
                ob=new("/d/xuehepai/obj/miji1");
                ob->move(environment(me));
                log_file("MISHI",sprintf("opened\n"));
                set("opened",1);
                return 1;
           }
           return 0;
}

int do_ketou()
{
           object me;

           me=this_player();

           if (!(me->query_temp("digg")))
                 return notify_fail("�ѿ��ں���������ͷ�ɡ�\n");

           message_vision("$N��ɫ���࣬���������ص��������˵ؿ��˾Ÿ���ͷ��\n",me);
           me->set_temp("ketou",1);
           return 1;
}

