// storeroom.c

inherit ROOM;

void init();
int do_open(string);

void create()
{
        set("short", "������");
        set("long", "����һ�������ң������ܲ�͸�硣ֻ�йر��ŵĴ���(door)��\n");
        set("item_desc" , ([
         "door" : "һ��ľ�ţ�Ҳ���ܴ򿪡�\n",
         ]) );
         setup();
       call_out("do_out",300);
}
void init()
{
 add_action("do_open","open");
}
int do_open(string arg)
{
  object me=this_player();
  object room;
 if( !arg|| arg!="door")
  return notify_fail("��Ҫ��ʲô��\n");
 if(!( room = find_object(__DIR__"yuanzi")) )
    room = load_object(__DIR__"yuanzi");
 if(!objectp(room))  return notify_fail("ERROR:not found 'yuanzi.c' \n");
 if(room->query_temp("lock")==1)
   return notify_fail("���Ѿ���������ס�ˡ�\n");
if( me->is_busy() )	
return notify_fail("����һ��������û����ɣ�\n");	
 message_vision("$N�����ƿ��ţ����˳�ȥ�����ְ�������������\n",me);
 message("vision", "�������˳��������ְ��������ˡ�\n",room);
 me->move(room);
me->start_busy(1);              	
 return 1;
}

void do_out()
{
    object *env=all_inventory(this_object());
    if (sizeof(env)>0){
       foreach (object npc in env){
          if (living(npc) && !userp(npc)) {
             npc->force_me("open door");
             break;
          }
       }
    }
    remove_call_out("do_out");
    call_out("do_out",300);
}

