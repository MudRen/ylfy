// ��̬��ͼ�Զ������� By ������(Wenwu) On 2006��1��6��
/* -----------------------------------------------
---  ����д�ĸ���̬��ͼ����ϵͳ��д�úܼ򵥣�����֮
---  ����д�����������Ϊ����������һ����ȥдÿ����
---  ����ϸ�ڡ��������ϵͳ�ܼ򵥣�����һ����СΪ
---  MAX_SIZE ��Room�ĵ�ͼ�������ڵ�һ��Room�����
---  һ��Room֮������һ�����Ե�·����Ȼ�����������
---  MAX_OUTS �����ڡ����� MAKE_AUTO_MAP_NPCS ����
---  ���з��� NPC��
-------------------------------------------------- */

#define MAKE_AUTO_MAP_NPCS

// ԭʼ��ͼ�ļ�
#define THIS_MAP_FILE "/clone/map/map.c"
// ��ڽӿ��ļ�
#define ENTER_MAP_FILE "/d/migong/migong1"
// ���ڽӿ��ļ�
#define OUT_MAP_FILE "/d/migong/migong2"
// NPC�ļ�
// -------------------------------------------
#define MAP_NPC_ONE   "/clone/map/npc/guai"
#define MAP_NPC_TWO   "/clone/map/npc/jinlong"
#define MAP_NPC_THREE "/d/migong/lev15/npc/boss"
#define MAP_NPC_FOUR  "/clone/map/npc/guai_boss"
#define MAP_NPC_FIVE  "/clone/map/npc/char_boss"
// -------------------------------------------
// ��ڷ���
#define ENTER_MAP_OUT "east"
// ���ڷ���
#define OUT_MAP_OUT "east"

#include <ansi.h>

inherit F_DBASE;

void create()
{
	seteuid( ROOT_UID );
	set("channel_id","��ͼ��������");
	set("fs_xx_msg",1);
	CHANNEL_D->do_channel( this_object(), "sys", HIM"��ͼ���������Ѿ�������\n"NOR);
	set_heart_beat(9);
}

// ����
string *direc = ({"north", "south", "east", "west", /*"northup", "southup", "eastup", "westup", "northdown", 
	"southdown", "eastdown", "westdown",*/ "northeast", "northwest", "southeast", "southwest", /*"up", "down",
	"enter", "out"*/
	});

// ��Ӧ�ӿ�
mapping pairs = ([
	"north":     "south",
	"south":     "north",
	"east":      "west",
	"west":      "east",
	"northup":   "southdown",
	"southup":   "northdown",
	"eastup":    "westdown",
	"westup":    "eastdown",
	"northdown": "southup",
	"southdown": "northup",
	"eastdown":  "westup",
	"westdown":  "eastup",
	"northeast": "southwest",
	"northwest": "southeast",
	"southeast": "northwest",
	"southwest": "northeast",
	"up":        "down",
	"down":      "up",
	"enter":     "out",
	"out":       "enter",
	]);

string set_room_outs(string out1, string out2, int room);

private void heart_beat()
{
	string this_file, this_enter, this_out, this_outs, *direc_new, this_room_file, this_npc;
	mixed *file;
	object obj, *ob;
	int i, k, rooms;

	rooms = 0;

	if ( time() - query("update_map_time") < 3600 * get_system_config(DATA_CONFIG_DIR "auto_map.h", "UPDATE_MAP_TIME") )
	{
		add("fs_xx_msg",1);

		if ( query("fs_xx_msg") % 20 == 1 )
		{

#ifdef XYZX_AUTO_MAP_DEBUG

			CHANNEL_D->do_channel( this_object(), "sys", HIW"���붯̬��ͼ����ʱ�仹�� "HIY+((3600 * UPDATE_MAP_TIME)-(time()-query("update_map_time")))/3600+HIW" Сʱ "HIG+(((3600 * UPDATE_MAP_TIME)-(time()-query("update_map_time")))%3600)/60+HIW" �֡�\n"NOR);

#endif

			message("channel:chat", HIY"������ˮ�¡�"+HIM"��̬��ͼ[����ɭ��]�����´θ���ʱ�仹�� "HIW+((3600 * get_system_config(DATA_CONFIG_DIR "auto_map.h", "UPDATE_MAP_TIME"))-(time()-query("update_map_time")))/3600+HIM" Сʱ "HIG+(((3600 * get_system_config(DATA_CONFIG_DIR "auto_map.h", "UPDATE_MAP_TIME"))-(time()-query("update_map_time")))%3600)/60+HIM" �֡�\n"NOR,users() );
		}
		
		return;
	}

	file = get_dir(get_system_config(DATA_CONFIG_DIR "auto_map.h", "AUTO_MAP"), -1);

	// ��鴴����ͼ�ļ������Ŀ¼
	if ( !sizeof(file) )
	{
		if ( file_size(get_system_config(DATA_CONFIG_DIR "auto_map.h", "AUTO_MAP")) != -2 )
		{
			CHANNEL_D->do_channel( this_object(), "sys", HIY"δָ������Ŀ¼����̬��ͼ����ʧ�ܡ�\n"NOR);
			return;
		}
	}
	else
	{
		// ɾ����ͼ�ļ�
		for (i = 0; i < sizeof(file); i++)
		{
			if ( i == 0 )
			{
				CHANNEL_D->do_channel( this_object(), "sys", HIY"��ʼ���ԭ�ж�̬��ͼ��\n"NOR);
				message("channel:chat", HIY"������ˮ�¡�"+HIM"��̬��ͼ[����ɭ��]��ʼ�����齨���¡�\n"NOR,users() );	
			}

			obj = find_object( get_system_config(DATA_CONFIG_DIR "auto_map.h", "AUTO_MAP") + file[i][0] );

			if ( obj )
			{
				ob = all_inventory(obj);

				if ( sizeof(ob) )
				{
					for (k = 0; k < sizeof(ob); k++)
					{
						if ( userp(ob[k]) )
						{
							tell_object(ob[k],HIY"����ɭ���Ѹ��£����Ժ��������ֻص�����ڴ���\n"NOR);
							ob[k]->move(ENTER_MAP_FILE);
						}
						else
							destruct(ob[k]);
					}
				}

				destruct(obj);
				rooms++;
			}

			if ( file_size(get_system_config(DATA_CONFIG_DIR "auto_map.h", "AUTO_MAP") + file[i][0]) != -1 )
				rm(get_system_config(DATA_CONFIG_DIR "auto_map.h", "AUTO_MAP") + file[i][0]);

			if ( i == sizeof(file) -1 )
				CHANNEL_D->do_channel( this_object(), "sys", HIY"ԭ�ж�̬��ͼ�����ϣ��������� "HIR + rooms +HIY" ��ROOM��ɾ�� "HIW + (i+1) + HIY" ���ļ�\n"NOR);
		}

		return;
	}

	if ( file_size(THIS_MAP_FILE) != -1 )
	{
		CHANNEL_D->do_channel( this_object(), "sys", HIG"��ʼ������СΪ "HIW + get_system_config(DATA_CONFIG_DIR "auto_map.h", "MAX_SIZE") + HIG" ������Ķ�̬��ͼ��\n"NOR);
		this_file = read_file(THIS_MAP_FILE);
		
		for ( i = 0; i < get_system_config(DATA_CONFIG_DIR "auto_map.h", "MAX_SIZE"); i++ )
		{
			// ��ڷ���
			if ( i == 0 )
			{
				this_enter = pairs[ENTER_MAP_OUT];
				direc_new = direc - ({this_enter});
				this_out = direc_new[random(sizeof(direc_new))];
				this_outs = "\n\"" + this_enter + "\" : \"" + ENTER_MAP_FILE +"\",\n" + 
					"\"" + this_out + "\" : __DIR__\"" + (i + 1) +"\",\n";
			}
			else if ( i == get_system_config(DATA_CONFIG_DIR "auto_map.h", "MAX_SIZE") -1 ) // ���ڷ���
			{
				this_enter = pairs[this_out];
				this_out = OUT_MAP_OUT;
				this_outs = "\n\"" + this_enter + "\" : __DIR__\"" + (i - 1) +"\",\n" + 
					"\"" + this_out + "\" : \"" + OUT_MAP_FILE +"\",\n";
			}
			else // �м䷿��
			{
				this_enter = pairs[this_out];
				direc_new = direc - ({this_enter});
				this_out = direc_new[random(sizeof(direc_new))];
				this_outs = "\n\"" + this_enter + "\" : __DIR__\"" + (i - 1) +"\",\n" + 
					"\"" + this_out + "\" : __DIR__\"" + (i + 1) +"\",\n";
			}

			if ( get_system_config(DATA_CONFIG_DIR "auto_map.h", "MAX_OUTS") )
				this_outs += set_room_outs(this_enter, this_out, i);

			this_room_file = replace_string(this_file, "set(\"exits\", ([", "set(\"exits\", ([" + this_outs);

#ifdef MAKE_AUTO_MAP_NPCS
			
			// ��һ�ֹ�
			if ( i > 4 && i % 5 == 0 )
			{
				this_npc = "\n\"" + MAP_NPC_ONE +"\" : 1,\n";
				this_room_file = replace_string(this_room_file, "set(\"objects\", ([", "set(\"objects\", ([" + this_npc);
			}

			// �ڶ��ֹ�
			if ( i > 149 && i % 150 == 0 )
			{
				this_npc = "\n\"" + MAP_NPC_TWO +"\" : 1,";
				this_room_file = replace_string(this_room_file, "set(\"objects\", ([", "set(\"objects\", ([" + this_npc);
			}

			// �����ֹ�
			if ( i > 498 && i % 499 == 0 )
			{
				this_npc = "\n\"" + MAP_NPC_THREE +"\" : 1,";
				this_room_file = replace_string(this_room_file, "set(\"objects\", ([", "set(\"objects\", ([" + this_npc);
			}

			// �����ֹ�
			if ( i > 49 && i % 50 == 0 )
			{
				this_npc = "\n\"" + MAP_NPC_FOUR +"\" : 1,";
				this_room_file = replace_string(this_room_file, "set(\"objects\", ([", "set(\"objects\", ([" + this_npc);
			}

			// �����ֹ�
			if ( i > 299 && i % 300 == 0 )
			{
				this_npc = "\n\"" + MAP_NPC_FIVE +"\" : 1,";
				this_room_file = replace_string(this_room_file, "set(\"objects\", ([", "set(\"objects\", ([" + this_npc);
			}

#endif
			
			write_file(get_system_config(DATA_CONFIG_DIR "auto_map.h", "AUTO_MAP") + i + ".c", this_room_file, 1);

			if ( i == get_system_config(DATA_CONFIG_DIR "auto_map.h", "MAX_SIZE") - 1 )
			{
				CHANNEL_D->do_channel( this_object(), "sys", HIM"��̬��ͼ������ϡ�\n"NOR);
				message("channel:chat", HIY"������ˮ�¡�"+HIM"��̬��ͼ[����ɭ��]������ϣ�������־֮ʿ�ֿ���������һ���ˡ�\n"NOR,users() );	
				set("update_map_time",time());
			}
		}
	}
	else
	{
		CHANNEL_D->do_channel( this_object(), "sys", HIY"δ�ҵ�ԭʼ��ͼ�ļ�����̬��ͼ����ʧ�ܡ�\n"NOR);
		return;
	}

	return;

}

// ��������ӿ�
string set_room_outs(string out1, string out2, int room)
{
	string outs, msg, *direc_gx;
	int j;

	direc_gx = direc - ({out1});
	direc_gx -= ({out2});

	for (j = 0; j < get_system_config(DATA_CONFIG_DIR "auto_map.h", "MAX_OUTS"); j++)
	{
		msg = direc_gx[random(sizeof(direc_gx))];
		direc_gx = direc_gx - ({msg});

		if ( j == 0 )
			outs = "\"" + msg + "\" : __DIR__\"" + random((int)get_system_config(DATA_CONFIG_DIR "auto_map.h", "MAX_SIZE")*2/3) +"\",\n";
		else
			outs += "\"" + msg + "\" : __DIR__\"" + random((int)get_system_config(DATA_CONFIG_DIR "auto_map.h", "MAX_SIZE")*2/3) +"\",\n";
	}

	return outs;
}