
#include <room.h>
#include <color.h>
#include <liebiao.h>

inherit F_CLEAN_UP;
inherit F_MAP_XY;

#include <item_sx.h>

mapping weapon_skill_type = ([
"sword"   :  "����",
"blade"   :  "����",
"axe"     :  "����",
"club"    :  "����",
"dagger"  :  "ì��",
"fork"    :  "�淨",
"hammer"  :  "����",
"staff"   :  "�ȷ�",
"whip"    :  "�޷�",
"spear"   :  "ǹ��",
"unarmed" :  "ȭ��",
"throwing":  "����"
]);

mapping armor_type = ([
"cloth"   :  "�·�",
"armor"   :  "����",
"boots"   :  "ѥ��",
"finger"  :  "��ָ",
"hands"   :  "����",
"head"    :  "ñ��",
"neck"    :  "����",
"shield"  :  "����",
"surcoat" :  "����",
"waist"   :  "����",
"wrists"  :  "����",
"pants"  :   "����"
]);

nosave string *all_exits = ({
	"east",
	"south",
	"west",
	"north",
	"eastup",
	"southup",
	"westup",
	"northup",
	"eastdown",
	"southdown",
	"westdown",
	"northdown",
	"northeast",
	"northwest",
	"southeast",
	"southwest",
	"up",
	"down",
	"enter",
	"out",
});

string *look_level_boy = ({
	BLU "ü����б����ͷѢ�ţ���������" NOR,
 	BLU "�������죬������ף�����ޱ�" NOR,
 	BLU "�����Ƥ��ͷ���������˲����ٿ��ڶ���" NOR,
	HIB "��ü���ۣ�������ߣ�������״" NOR,
	HIB "��ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц" NOR,
 	NOR "��հ��ݣ��ݹ����꣬������̾" NOR,
 	NOR "ɵͷɵ�ԣ��ճպ�����������Ҳ��ʵ" NOR,
 	NOR "��òƽƽ�������������ʲôӡ��" NOR,
 	YEL "�����Բ���������⣬���ζ���" NOR,
 	YEL "��Բ���������ڷ����Ǹ񲻷�" NOR,
 	RED "üĿ���㣬�����󷽣�һ���˲�" NOR,
 	RED "˫�۹⻪Ө��͸���������ǵĹ�â" NOR,
 	HIY "�ٶ���������ˮ�����̷��飬������������Ŀ��" NOR,
 	HIY "˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ�" NOR,
 	HIR "�����촽�����˿��Σ���ֹ��������" NOR,
 	HIR "��������Ŀ�����ǣ����˹�Ŀ����" NOR,
 	MAG "�������񣬷�ױ��������������" NOR,
 	MAG "Ʈ�ݳ�������������" NOR,
 	MAG "�����ʣ��������������������ٷ�" NOR,
 	HIM "������ˬ���Ǹ����棬��������" NOR,
 	HIM "һ���������ȣ��ɷ���ǣ���ֹ����" NOR,
});

string *look_level_girl = ({
	BLU "�������Σ�״��ҹ��" NOR,
	BLU "���б�ۣ���ɫ�Ұܣ�ֱ����һ��" NOR,
	BLU "����ü�������ۣ���Ƥ�Ʒ�������һ��������" NOR,
	HIB "��С�綹��üëϡ�裬�����צ����������" NOR,
	HIB "һ�����������һ����û�ø�" NOR,
  	NOR "�������Ƥɫ�ֺڣ���ª����" NOR,
  	NOR "�ɻƿ��ݣ���ɫ���ƣ�����Ů��ζ" NOR,
  	YEL "�����С�������޹⣬��������" NOR,
  	YEL "�䲻���£���Ҳ�׾�����Щ����֮��" NOR,
  	RED "����΢�ᣬ�ŵ��������¿���" NOR,
  	RED "�������ģ�����Ө͸��������˼" NOR,
  	HIR "��С���磬���������������������" NOR,
  	HIR "�������󣬼���ʤѩ��Ŀ����ˮ" NOR,
  	HIW "���۰���������ҩ���̣����￴��" NOR,
  	HIW "����ϸ������欶��ˣ�����һ������������" NOR,
  	MAG "�����������������£�����ܳ�������" NOR,
  	MAG "üĿ�续������ʤѩ�����ν�����߻�" NOR,
  	MAG "�������������Ż���ɽ�����˼�֮����" NOR,
  	HIM "������ϼ���������񣬻�����������" NOR,
  	HIM "�������ɣ���մһ˿�̳�" NOR,
  	HIM "����"+HIW+"������"+HIM+"�������ƻã��Ѳ����Ƿ�������" NOR,
});

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object obj;
	int result;
	
	if( !arg )
		result = look_room(me, environment(me));
	else if( (obj = present(arg, environment(me))) ||  (obj = present(arg, me)) )
	{
		if( obj->is_character() )
			result = look_living(me, obj);
		else
			result = look_item(me, obj);
	}
	else
		result = look_room_item(me, arg);
	
	return result;
}

int sort_exits(string str1,string str2)
{
	int i, j;
	
	if ( strcmp(str1,"a") < 0 && strcmp(str2,"a")<0 )
	{
		if (strlen(str1) < strlen(str2))
			return -1;
		
		if ( strlen(str1) == strlen(str2) )
			return strcmp(str1,str2);
		
		return 1;
	}
	else
	{
		i = member_array(str1, all_exits);
		j = member_array(str2, all_exits);
		
		if ( i > 0 && j > 0 )
			return i - j;
		else
			return strcmp(str1,str2);
	}
}

// ��ʱ��ͼ
void realtime_map(object me,object env)
{
        object room_obj;
        mapping exits;
    int i;
        string map_room, map_room2,jiantou;
     string *dirs;
        mapping alldirs=([      
                        "northwest" : "          ",
                        "north"     : "          ",
                        "northup"   : "          ",
                        "northeast" : "          ",
                        "west"      : "          ",
                        "east"      : "          ",
                        "southeast" : "          ",
                        "south"     : "          ",
                        "southwest" : "          ",
                        "southdown" : "          ",
                        "eastup"    : "          ",
                        "southup"   : "          ",
                        "northdown" : "          ",
                        "eastdown"  : "          ",
                        "westup"    : "          ",
                        "westdown"  : "          ",
                        "enter"     : "          ",
                        "out"       : "          ",
                        "up"        : "          ",
                        "down"      : "          ",
                        "left"      : "          ",
                        "right"     : "          ",
                        ]);  
       if( mapp(exits = env->query("exits")) ) 
        {                       
                dirs = keys(exits);
		   
                for(i=0; i< sizeof(dirs); i++)
                {
                        if(!room_obj = find_object(exits[dirs[i]])) {
                                room_obj = load_object(exits[dirs[i]]);
				    }
                        if(room_obj){
                                if (room_obj->query("short"))
							alldirs[dirs[i]] = room_obj->query("short");
					}
        
                }
        
                jiantou="  ";
                map_room2=alldirs["enter"];
                if(alldirs["enter"]!="          ")
				{
                        map_room2=alldirs["enter"];
                        jiantou=HIR+"��"+NOR;
                }
                if(alldirs["up"]!="          "){
                        map_room2=alldirs["up"];
                        jiantou=HIC"��"+NOR;
                        }
                if(alldirs["northdown"]!="          "){
                        map_room2=alldirs["northdown"];
                        jiantou="��";
                        }
                if(alldirs["northup"]!="          "){
                        map_room2=alldirs["northup"];
                        jiantou="��";
                        }
                if(alldirs["north"]!="          "){
                        map_room2=alldirs["north"];
                        jiantou="��";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room+" ";
                                map_room =" "+map_room;
                        }
                printf("             %10s  %-10s  %-10s\n",
                alldirs["northwest"],map_room,alldirs["northeast"]);
                
                printf("                        %s   %s   %s\n",
                alldirs["northwest"]=="          " ? "  ":"��",
                jiantou,
                alldirs["northeast"]=="          " ? "  ":"��");
                
                jiantou="  ";
                map_room2=alldirs["westdown"];
                if(map_room2!="          ")
                                jiantou="��";
                if(alldirs["left"]!="          "){
                        map_room2=alldirs["left"];
                        jiantou="��";
                        }
                if(alldirs["westup"]!="          "){
                        map_room2=alldirs["westup"];
                        jiantou="��";
                        }
                if(alldirs["west"]!="          "){
                        map_room2=alldirs["west"];
                        jiantou="--";
                        }
                printf("             %10s%s",map_room2,jiantou);        
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("%s",map_room);
                
                jiantou="  ";
                map_room2=alldirs["eastup"];
                if(map_room2!="          ")
                                jiantou="��";
                if(alldirs["right"]!="          "){
                        map_room2=alldirs["right"];
                        jiantou="��";
                        }
                if(alldirs["eastdown"]!="          "){
                        map_room2=alldirs["eastdown"];
                        jiantou="��";
                        }
                if(alldirs["east"]!="          "){
                        map_room2=alldirs["east"];
                        jiantou="--";
                        }
                
                printf("%s%-10s\n",jiantou,map_room2);
                
                jiantou="  ";
                map_room2=alldirs["out"];
                if(alldirs["out"]!="          "){
                        map_room2=alldirs["out"];
                        jiantou=HIR+"��"+NOR;
                        }
                if(alldirs["down"]!="          "){
                        map_room2=alldirs["down"];
                        jiantou=HIC+"��"+NOR;
                        }
                
                if(alldirs["southdown"]!="          "){
                                map_room2=alldirs["southdown"];
                                jiantou="��";
                                }
                if(alldirs["southup"]!="          "){
                        map_room2=alldirs["southup"];
                        jiantou="��";
                        }
                if(alldirs["south"]!="          "){
                        map_room2=alldirs["south"];
                        jiantou="��";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room + " ";
                                map_room =" "+map_room;
                        }
                printf("                        %s   %s   %s\n",
                alldirs["southwest"]=="          " ? "  ":"��",
                jiantou,
                alldirs["southeast"]=="          " ? "  ":"��");
                printf("             %10s  %-10s  %-10s\n",
                alldirs["southwest"],map_room,alldirs["southeast"]);
                
                        
        }       
        else
        {
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("\n                            %s\n",map_room);
                
        }
        return;
}

// Tomudͷ��
string look_icon(object me, object ob)
{
	mixed tmp;
	string icon;

	if ( !objectp(ob) )
		return "";
	if ( me->query("xieyi/zmud") )
		return "";
	
	if ( tmp = ob->query("icon") )
	{
		if ( intp(tmp) )
			icon = sprintf("%d", tmp);
		else if ( stringp(tmp) )
			icon = tmp;
		else 
		{
			if ( living(ob) || ob->is_character() ) icon = "00901";
			else icon = "00961";
		}
	}
	else
	{
		if ( userp(ob) ) icon = (ob->query("gender") == "����")?"1174":"1173";	
		else if ( living(ob) || ob->is_character() ) icon = "00901";
		else icon = "00961";
	}
	
	while ( strlen(icon) < 5 )
	{
		icon = "0" + icon;
	}
	
	return L_ICON(icon);
}

int look_room(object me, object env)
{
	int i, j, k, l, x, y, show_lvl;
	object *inv;
	mapping exits, *data;
	string str, *dirs, desc;
	mapping buffo = ([]), buffobj = ([]);
	string bfile, place_name;
    string short, short_xy, long, exit, msg;

    k = 0;
	data = allocate(3000);
	show_lvl = to_int(me->query("env/brief"));
	
	if( me->query("position") == "webuser" )
	{
		if( !env ) 
		{
			write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
			return 1;
		}
		
		short = sprintf(WEBBLK "��" WEBNOR WEBRED " %s"  WEBNOR WEBBLK "��" + WEBNOR, env->query("short"));
		short += wizardp(me)? file_name(env): "";
		desc = env->query("long");
		long = desc + "<br>����" + WEBYEL + implode(explode((env->query("outdoors")?"":"���⣺") + NATURE_D->outdoor_room_description(), "\n"), "")  + WEBNOR;
		exit = "";
		
		if( mapp(exits = env->query("exits")) )
		{
			dirs = keys(exits);
			for(i=0; i<sizeof(dirs); i++)
			{
				if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
					dirs[i] = 0;
			}
			
			dirs -= ({ 0 });
			
			if( sizeof(dirs)==0 )
				exit = "    ����û���κ����Եĳ�·��";
			else if( sizeof(dirs)==1)
				exit = "    ����Ψһ�ĳ����� <a target=nothing href=\\\"/Command/go "  + dirs[0] + "\\\"" + WEBRED + dirs[0]  + "</a>" + WEBNOR + "��";
			else
			{
				exit = "    �������Եĳ����� ";
				for (i = 0; i < sizeof(dirs) - 2; i++)
				{
					exit += sprintf("<a target=nothing href=\\\"/Command/go %s\\\">%s</a>��", dirs[i], dirs[i]);
				}
				
				exit += sprintf("<a target=nothing href=\\\"/Command/go %s\\\">%s</a>��", dirs[sizeof(dirs) - 2], dirs[sizeof(dirs) - 2]);
				exit += sprintf("<a target=nothing href=\\\"/Command/go %s\\\">%s</a>", dirs[sizeof(dirs) - 1], dirs[sizeof(dirs) - 1]);
			}
		}
		
		inv = all_inventory(env);
		str = "";
		for(i=0; i<sizeof(inv); i++)
		{
			if( inv[i]==me ) continue;
			if( inv[i]->query("no_shown")) continue;
			if( !me->visible(inv[i]) ) continue;
			
			bfile=base_name(inv[i]);
			
			if ( member_array(bfile,keys(buffo)) == -1 )
			{
				buffo[bfile]=1;
				buffobj[bfile]=inv[i];
				str += sprintf("<a target=nothing href=\\\"/Command/look %s\\\">%s</a><br><br>",inv[i]->query("id"), inv[i]->short());
			}
			else
			{
				buffo[bfile] ++;
				str += sprintf("<a target=nothing href=\\\"/Command/look %s %d\\\">%s</a><br><br>",inv[i]->query("id"), buffo[bfile], inv[i]->short());
			}
		}
		
		printf(JSP "parent.show_inv(\"%s\")" NSP, str);
		printf(JSP "parent.look_room(\"%s\", \"%s\", \"%s\")" NSP, short, long, exit);
		
		return 1;
	}
	else
	{
		if ( !me->query("xieyi/zmud") )
		{
			msg = "";

			if ( me->is_fighting() || me->query("env/map_xy_msg") || me->query("env/map_xy_msg") > 0 )
			{
				if ( me->query("xysys_map_xy/x") > 1 )
					msg += "west;";
			
				if ( me->query("xysys_map_xy/x") < 6 )
					msg += "east;";

				if ( me->query("xysys_map_xy/y") > 1 )
					msg += "north;";

				if ( me->query("xysys_map_xy/y") < 6 )
					msg += "south;";

				if ( me->query("xysys_map_xy/x") > 1 && me->query("xysys_map_xy/y") > 1 )
					msg +="northwest;";

				if ( me->query("xysys_map_xy/x") > 1 && me->query("xysys_map_xy/y") < 6 )
					msg +="southwest;";

				if ( me->query("xysys_map_xy/x") < 6 && me->query("xysys_map_xy/y") > 1 )
					msg +="northeast;";

				if ( me->query("xysys_map_xy/x") < 6 && me->query("xysys_map_xy/y") < 6 )
					msg +="southeast;";
			}
		}

		if( !env )
		{
			write("������ܻ����ɵ�һƬ��ʲ��Ҳû�С�\n");
			return 1;
		}
		
		if ( virtualp(env) && sscanf(base_name(env), "/adm/daemons/vrm_server/%s/%d/%d", place_name, x, y)==3 ) 
		{
			short_xy = HIY"[���꣺��="HIG+x+HIY"����="HIC+y+HIY"]";
		}
		else
			short_xy = "";
		
		if ( env->query("outdoors") )
		{
			if ( wizardp(me) && !me->query("env/show_room") )
				str = sprintf( HIR +"��"+HIG"%s"+HIR"��%s"NOR + " - %s\n    %s%s", env->query("short"), short_xy, SECURITY_D->valid_read(file_name(env),me)? file_name(env): "", show_lvl>3?"":env->query("long"), (env->query("outdoors")&&show_lvl<4)? NATURE_D->outdoor_room_description() : "" );
			else
				str = sprintf( HIR +"��"+HIG"%s"+HIR"��%s"NOR + "\n    %s%s", env->query("short"), short_xy, show_lvl>3?"":env->query("long"), (env->query("outdoors")&&show_lvl<4)? NATURE_D->outdoor_room_description() : "" );
		}
		else
		{
			if (wizardp(me) && !me->query("env/show_room"))
				str = sprintf( HIC +"��"+NOR HIR"%s"+HIC"��%s"NOR + " - %s\n    %s%s", env->query("short"), short_xy, SECURITY_D->valid_read(file_name(env),me)? file_name(env): "", show_lvl>3?"":env->query("long"), (env->query("outdoors")&&show_lvl<4)? NATURE_D->outdoor_room_description() : "" );
			else str = sprintf( HIC +"��"+HIR"%s"+HIC"��%s"NOR + "\n    %s%s", env->query("short"), short_xy, show_lvl>3?"":env->query("long"), (env->query("outdoors")&&show_lvl<4)? NATURE_D->outdoor_room_description() : "" );
		}
		
		if ( !me->query("xieyi/zmud") )
			str += CLEAN0;
		
		if( mapp(exits = env->query("exits")) )
		{
			dirs = keys(exits);
			for(i=0; i<sizeof(dirs); i++)
			{
				if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
					dirs[i] = 0;
			}
			
			dirs -= ({ 0 });
			
			if( sizeof(dirs)==0 )
			{
				str += NOR CYN"    ����û���κ����Եĳ�·��\n";

				if(!me->query("xieyi/zmud"))
					str += ADDWAY(msg);
			}
			else if( sizeof(dirs)==1 )
			{
				if(!me->query("xieyi/zmud"))
					str +=ADDWAY(msg + dirs[0]);
				
				str += "    "+HIC"Ψһ��"+HIY"��"+HIW" ���� "NOR+HIY"��"NOR+": " + HIR + dirs[0] + NOR + "��\n";
			}
			else
			{
				dirs = sort_array(dirs,"sort_exits");
				str += sprintf("    "+HIY"��"+HIW" ���� "NOR+HIY"��"NOR+": "+ HIW + "%s" + HIY" �� "NOR + HIW"%s" +NOR + "��\n", implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
				
				if(!me->query("xieyi/zmud"))
					str += sprintf(ADDWAY(msg + implode(dirs[0..sizeof(dirs)-1], ";")));
			}
		}
		else
		{
			str += NOR CYN"    ����û���κ����Եĳ�·��\n"+NOR;
			
			if(!me->query("xieyi/zmud"))
				str += ADDWAY(msg);
		}
		
		inv = all_inventory(env);
		for (i = 0; i < sizeof(inv); i++)
		{
			reset_eval_cost();
			if ( inv[i]!=me 
				&& me->visible(inv[i]) 
				&& !inv[i]->query("money_id") 
				&& !inv[i]->query_temp("check_only") 
				&& !inv[i]->is_character() )
			{
				data[k]=([]);
				for(j = i; j < sizeof(inv); j++ )
				{
					if ( inv[i]->query("name")==inv[j]->query("name") 
						&& inv[i]->query("id")==inv[j]->query("id")
						&& !inv[j]->query_temp("check_only") )
					{
						data[k]["id"]=inv[i]->short();
						data[k]["unit"]=inv[i]->query("unit");
						data[k]["num"]= data[k]["num"] + 1;
						inv[j]->set_temp("check_only", 1);
					}
					else
						continue;
				}
				
				k++;
			}
			else
				continue;
		}
		
		for (i = 0; i < sizeof(inv); i++)
		{
			reset_eval_cost();
			if ( !inv[i]->query_temp("check_only") && inv[i]!=me && me->visible(inv[i]) )
				str += sprintf("%s%s\n", "  ", inv[i]->short());
			
			if (inv[i]!=me && !me->query("xieyi/zmud"))
			{
				if(!(wizardp(inv[i]) && inv[i]->query("env/invisibility") == 10))
				{
					if ( i > 50 )
					{
						if ( inv[i]->is_character() || inv[i]->query("startroom") == base_name(env) )
							str += ADD0(inv[i]);
					}
					else
						str += ADD0(inv[i]);
				}
			}
		}

		for (i = 0; i < sizeof(inv); i++)
			if ( inv[i]->query_temp("check_only") )
				inv[i]->delete_temp("check_only");

		if (k > 0)
		{
			for (l = 0; l < k; l++)
				str = sprintf("%s%s%s\n", str,  (data[l]["num"]==1)? "  ":"  "+ chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"]);
		}

		// ��ʱ��ͼ
		if( !me->query("temp_time_map") && show_lvl<5 )
		{
			if ( base_name(env) != "/d/migong/migong1" && base_name(env) != "/d/migong/migong2" )
				realtime_map(me, env);
		}

		if ( !me->query("xieyi/zmud") && me->query("env/myhp_show") )
			str += ROOMNAME(filter_color(env->query("short")));
		
		write(str);

		return 1;
	}
}

int look_item(object me, object obj)
{
	mapping is_bind;
    mixed *inv;
    string prep, *bind_ids;
	int i, v_num, lvl;

    if (!me->visible(obj)) { write("��Ҫ��ʲô��\n"); return 1; }
    if( me->query("position") == "webuser" )
	{
		//����ħ����ָ�������⴦��
		if ( obj->query("old_copy_log") && obj->query("diablo/only_me") != me->query("id") )
			write(obj->query("old_copy_log"));
		else
			write(obj->long());

	inv = all_inventory(obj);
	if( !obj->is_closed() && sizeof(inv)) {
		switch( (string)obj->query("prep") ) {
			case "on":
				prep = "��";
				break;
			case "under":
				prep = "��";
				break;
			case "behind":
				prep = "��";
				break;
			case "inside":
				prep = "��";
				break;
			default:
				prep = "��";
				break;
                        }
		inv = map_array(inv, "inventory_look", this_object() );
		message("vision", sprintf("%s���У�\n  %s\n", prep,
			implode(inv, "\n  ") ), me);
	}
	return 1;
} else {
	// Add By Wenwu
	//------------------------------------------------------
	write(HIW"�����ơ���"+NOR+obj->query("name")+NOR+"("+obj->query("id")+")\n");
	//------------------------------------------------------
	//����ħ����ָ�������⴦��
	if ( obj->query("old_copy_log") && obj->query("diablo/only_me") != me->query("id") )
		write(HIY"����������"+NOR+obj->query("old_copy_log"));
	else
		write(HIY"����������"+NOR+obj->long());
	if (obj->query("item_t")){
			write("ʱЧ��"+ CHINESE_D->chinese_period(obj->query("item_t")-time())+"\n");
		}
	// ������ʾ
	// ����
	if ( obj->query("weapon_prop") )
	{
		v_num = 0;
		for (i = 0; i < sizeof(weapon_shuxing); i++)
		{
			if ( obj->query("weapon_prop/" + keys(weapon_shuxing)[i]) )
				v_num++;
		}
		write(HIM"\t����Ʒ�ף�  "+chinese_number(v_num)+"��\n"NOR);
		write(YEL"\t���ӵȼ���  "+chinese_number(obj->query("weapon_prop/level"))+"��\n"NOR);

			if ( obj->query("flag") & 1 )
				write(HIY"\tʹ�����ͣ�"HIY"  ˫��\n"NOR);
			else 
				write(HIY"\tʹ�����ͣ�"HIY"  ����\n"NOR);

		write(HIM"\tӦ�����ͣ�  "HIB+weapon_skill_type[obj->query("skill_type")]+"\n"NOR);

		// �󶨵�װ�������޷�װ����
		if ( mapp(is_bind=obj->query("bind_master_level")) )
		{	
			bind_ids = keys(is_bind);
			write(HIC"\t�����ͣ�  "HIR"�Ѱ�("+bind_ids[0]+")\n"NOR);
			
		} else if ( lvl = obj->query("xyzx_sys/bind_type") ) {
			if ( lvl == 1 ) 
				write(HIC"\t�����ͣ�  "HIY"װ����\n"NOR);
			else if ( lvl == 2 ) 
				write(HIC"\t�����ͣ�  "HIY"ʰȡ��\n"NOR);
			else
				write(HIC"\t�����ͣ�  "HIW"δ֪\n"NOR);
		}
		else
			write(HIC"\t�����ͣ�  "HIW"����\n"NOR);

		if ( obj->query("weapon_prop/damage") )
			write(HIW"\t��������"HIG"+ "HIW+obj->query("weapon_prop/damage")+"\n"NOR);

		if ( obj->query("weapon_prop/strength") )
			write(HIB"\t����������"HIG"+ "HIW+obj->query("weapon_prop/strength")+"\n"NOR);

		if ( obj->query("weapon_prop/intelligence") )
			write(HIM"\t����������"HIG"+ "HIW+obj->query("weapon_prop/intelligence")+"\n"NOR);

		if ( obj->query("weapon_prop/constitution") )
			write(HIY"\t����������"HIG"+ "HIW+obj->query("weapon_prop/constitution")+"\n"NOR);

		if ( obj->query("weapon_prop/dexerity") )
			write(HIG"\t��������"HIG"+ "HIW+obj->query("weapon_prop/dexerity")+"\n"NOR);

		if ( obj->query("weapon_prop/karma") )
			write(YEL"\t��Ե������"HIG"+ "HIW+obj->query("weapon_prop/karma")+"\n"NOR);

		if ( obj->query("weapon_prop/personality") )
			write(MAG"\t��ò������"HIG"+ "HIW+obj->query("weapon_prop/personality")+"\n"NOR);

		if ( obj->query("weapon_prop/dodge") )
			write(HIG"\t�Ṧ������"HIG"+ "HIW+obj->query("weapon_prop/dodge")+"\n"NOR);

		if ( obj->query("weapon_prop/unarmed") )
			write(HIY"\tȭ��������"HIG"+ "HIW+obj->query("weapon_prop/unarmed")+"\n"NOR);

		if ( obj->query("weapon_prop/force") )
			write(YEL"\t�ڹ�������"HIG"+ "HIW+obj->query("weapon_prop/force")+"\n"NOR);

		if ( obj->query("weapon_prop/parry") )
			write(HIB"\t�м�������"HIG"+ "HIW+obj->query("weapon_prop/parry")+"\n"NOR);

		if ( obj->query("weapon_prop/sword") )
			write(HIW"\t����������"HIG"+ "HIW+obj->query("weapon_prop/sword")+"\n"NOR);

		if ( obj->query("weapon_prop/blade") )
			write(HIY"\t����������"HIG"+ "HIW+obj->query("weapon_prop/blade")+"\n"NOR);

		if ( obj->query("weapon_prop/axe") )
			write(HIB"\t����������"HIG"+ "HIW+obj->query("weapon_prop/axe")+"\n"NOR);

		if ( obj->query("weapon_prop/stick") )
			write(YEL"\t����������"HIG"+ "HIW+obj->query("weapon_prop/stick")+"\n"NOR);

		if ( obj->query("weapon_prop/staff") )
			write(CYN"\t�ȷ�������"HIG"+ "HIW+obj->query("weapon_prop/staff")+"\n"NOR);

		if ( obj->query("weapon_prop/spear") )
			write(HIB"\tǹ��������"HIG"+ "HIW+obj->query("weapon_prop/spear")+"\n"NOR);

		if ( obj->query("weapon_prop/fork") )
			write(HIB"\t�淨������"HIG"+ "HIW+obj->query("weapon_prop/fork")+"\n"NOR);

		if ( obj->query("weapon_prop/club") )
			write(HIB"\t����������"HIG"+ "HIW+obj->query("weapon_prop/club")+"\n"NOR);

		if ( obj->query("weapon_prop/throwing") )
			write(HIR"\t����������"HIG"+ "HIW+obj->query("weapon_prop/throwing")+"\n"NOR);

		if ( obj->query("weapon_prop/hammer") )
			write(GRN"\t����������"HIG"+ "HIW+obj->query("weapon_prop/hammer")+"\n"NOR);

		if ( obj->query("weapon_prop/taoism") )
			write(HIM"\t��ѧ�ķ���"HIG"+ "HIW+obj->query("weapon_prop/taoism")+"\n"NOR);

		if ( obj->query("weapon_prop/whip") )
			write(HIG"\t�޷�������"HIG"+ "HIW+obj->query("weapon_prop/whip")+"\n"NOR);

		if ( obj->query("weapon_prop/strike") )
			write(HIG"\t�Ʒ�������"HIG"+ "HIW+obj->query("weapon_prop/strike")+"\n"NOR);

		if ( obj->query("weapon_prop/finger") )
			write(HIG"\tָ��������"HIG"+ "HIW+obj->query("weapon_prop/finger")+"\n"NOR);

		if ( obj->query("weapon_prop/magic") )
			write(HIM"\t����������"HIG"+ "HIW+obj->query("weapon_prop/magic")+"\n"NOR);

		if ( obj->query("weapon_prop/spells") )
			write(HIM"\t����������"HIG"+ "HIW+obj->query("weapon_prop/spells")+"\n"NOR);

		if ( obj->query("weapon_prop/poison") )
			write(HIG"\t����������"HIG"+ "HIW+obj->query("weapon_prop/poison")+"\n"NOR);

		if ( obj->query("weapon_prop/hand") )
			write(HIW"\t�ַ�������"HIG"+ "HIW+obj->query("weapon_prop/hand")+"\n"NOR);

		if ( obj->query("weapon_prop/cuff") )
			write(HIY"\tȭ��������"HIG"+ "HIW+obj->query("weapon_prop/cuff")+"\n"NOR);

		if ( obj->query("weapon_prop/claw") )
			write(HIW"\tצ��������"HIG"+ "HIW+obj->query("weapon_prop/claw")+"\n"NOR);
	}
	else if ( obj->query("armor_prop") ) // ����
	{
		v_num = 0;
		for (i = 0; i < sizeof(armor_shuxing); i++)
		{
			if ( obj->query("armor_prop/" + keys(armor_shuxing)[i]) )
				v_num++;
		}
		write(HIM"\t����Ʒ�ף�  "+chinese_number(v_num)+"��\n"NOR);
		write(YEL"\t���ӵȼ���  "+chinese_number(obj->query("armor_prop/level"))+"��\n"NOR);

		if ( obj->query("armor_type") )
			write(HIY"\tʹ�����ͣ�  "HIY+armor_type[obj->query("armor_type")]+"\n"NOR);

		if ( obj->query("female_only") )
			write(HIC"\tʹ�����  "HIM"Ů��\n"NOR);
		else
			write(HIC"\tʹ�����  "HIG"ͨ��\n"NOR);

		// �󶨵�װ�������޷�װ����
		if ( mapp(is_bind=obj->query("bind_master_level")) )
		{
			bind_ids = keys(is_bind);
			write(HIC"\t�����ͣ�  "HIR"�Ѱ�("+bind_ids[0]+")\n"NOR);
			
		} else if ( lvl = obj->query("xyzx_sys/bind_type") ) {
			if ( lvl == 1 ) 
				write(HIC"\t�����ͣ�  "HIY"װ����\n"NOR);
			else if ( lvl == 2 ) 
				write(HIC"\t�����ͣ�  "HIY"ʰȡ��\n"NOR);
			else
				write(HIC"\t�����ͣ�  "HIW"δ֪\n"NOR);
		}
		else
			write(HIC"\t�����ͣ�  "HIW"����\n"NOR);

		if ( obj->query("armor_prop/armor") )
			write(HIW"\t���������"HIG"+ "HIW+obj->query("armor_prop/armor")+"\n"NOR);

		if ( obj->query("armor_prop/strength") )
			write(HIB"\t����������"HIG"+ "HIW+obj->query("armor_prop/strength")+"\n"NOR);

		if ( obj->query("armor_prop/intelligence") )
			write(HIM"\t����������"HIG"+ "HIW+obj->query("armor_prop/intelligence")+"\n"NOR);

		if ( obj->query("armor_prop/constitution") )
			write(HIY"\t����������"HIG"+ "HIW+obj->query("armor_prop/constitution")+"\n"NOR);

		if ( obj->query("armor_prop/dexerity") )
			write(HIG"\t��������"HIG"+ "HIW+obj->query("armor_prop/dexerity")+"\n"NOR);

		if ( obj->query("armor_prop/karma") )
			write(YEL"\t��Ե������"HIG"+ "HIW+obj->query("armor_prop/karma")+"\n"NOR);

		if ( obj->query("armor_prop/personality") )
			write(MAG"\t��ò������"HIG"+ "HIW+obj->query("armor_prop/personality")+"\n"NOR);

		if ( obj->query("armor_prop/armor_vs_force") )
			write(HIY"\t�������壺"HIG"+ "NOR+YEL+obj->query("armor_prop/armor_vs_force")+"\n"NOR);

		if ( obj->query("armor_prop/dodge") )
			write(HIG"\t�Ṧ������"HIG"+ "HIW+obj->query("armor_prop/dodge")+"\n"NOR);

		if ( obj->query("armor_prop/unarmed") )
			write(HIY"\tȭ��������"HIG"+ "HIW+obj->query("armor_prop/unarmed")+"\n"NOR);

		if ( obj->query("armor_prop/force") )
			write(YEL"\t�ڹ�������"HIG"+ "HIW+obj->query("armor_prop/force")+"\n"NOR);

		if ( obj->query("armor_prop/parry") )
			write(HIB"\t�м�������"HIG"+ "HIW+obj->query("armor_prop/parry")+"\n"NOR);

		if ( obj->query("armor_prop/sword") )
			write(HIW"\t����������"HIG"+ "HIW+obj->query("armor_prop/sword")+"\n"NOR);

		if ( obj->query("armor_prop/blade") )
			write(HIY"\t����������"HIG"+ "HIW+obj->query("armor_prop/blade")+"\n"NOR);

		if ( obj->query("armor_prop/axe") )
			write(HIB"\t����������"HIG"+ "HIW+obj->query("armor_prop/axe")+"\n"NOR);

		if ( obj->query("armor_prop/stick") )
			write(YEL"\t����������"HIG"+ "HIW+obj->query("armor_prop/stick")+"\n"NOR);

		if ( obj->query("armor_prop/staff") )
			write(CYN"\t�ȷ�������"HIG"+ "HIW+obj->query("armor_prop/staff")+"\n"NOR);

		if ( obj->query("armor_prop/spear") )
			write(HIB"\tǹ��������"HIG"+ "HIW+obj->query("armor_prop/spear")+"\n"NOR);

		if ( obj->query("armor_prop/fork") )
			write(HIB"\t�淨������"HIG"+ "HIW+obj->query("armor_prop/fork")+"\n"NOR);

		if ( obj->query("armor_prop/club") )
			write(HIB"\t����������"HIG"+ "HIW+obj->query("armor_prop/club")+"\n"NOR);

		if ( obj->query("armor_prop/throwing") )
			write(HIR"\t����������"HIG"+ "HIW+obj->query("armor_prop/throwing")+"\n"NOR);

		if ( obj->query("armor_prop/hammer") )
			write(GRN"\t����������"HIG"+ "HIW+obj->query("armor_prop/hammer")+"\n"NOR);

		if ( obj->query("armor_prop/taoism") )
			write(HIM"\t��ѧ�ķ���"HIG"+ "HIW+obj->query("armor_prop/taoism")+"\n"NOR);

		if ( obj->query("armor_prop/whip") )
			write(HIG"\t�޷�������"HIG"+ "HIW+obj->query("armor_prop/whip")+"\n"NOR);

		if ( obj->query("armor_prop/strike") )
			write(HIG"\t�Ʒ�������"HIG"+ "HIW+obj->query("armor_prop/strike")+"\n"NOR);

		if ( obj->query("armor_prop/finger") )
			write(HIG"\tָ��������"HIG"+ "HIW+obj->query("armor_prop/finger")+"\n"NOR);

		if ( obj->query("armor_prop/magic") )
			write(HIM"\t����������"HIG"+ "HIW+obj->query("armor_prop/magic")+"\n"NOR);

		if ( obj->query("armor_prop/spells") )
			write(HIM"\t����������"HIG"+ "HIW+obj->query("armor_prop/spells")+"\n"NOR);

		if ( obj->query("armor_prop/poison") )
			write(HIG"\t����������"HIG"+ "HIW+obj->query("armor_prop/poison")+"\n"NOR);

		if ( obj->query("armor_prop/hand") )
			write(HIW"\t�ַ�������"HIG"+ "HIW+obj->query("armor_prop/hand")+"\n"NOR);

		if ( obj->query("armor_prop/cuff") )
			write(HIY"\tȭ��������"HIG"+ "HIW+obj->query("armor_prop/cuff")+"\n"NOR);

		if ( obj->query("armor_prop/claw") )
			write(HIW"\tצ��������"HIG"+ "HIW+obj->query("armor_prop/claw")+"\n"NOR);
	} else {
		// �󶨵�װ�������޷�װ����
		if ( mapp(is_bind=obj->query("bind_master_level")) )
		{
			bind_ids = keys(is_bind);
			write(HIC"\t�����ͣ�  "HIR"�Ѱ�("+bind_ids[0]+")\n"NOR);
			
		} else if ( lvl = obj->query("xyzx_sys/bind_type") ) {
			if ( lvl == 1 ) 
				write(HIC"\t�����ͣ�  "HIY"װ����\n"NOR);
			else if ( lvl == 2 ) 
				write(HIC"\t�����ͣ�  "HIY"ʰȡ��\n"NOR);
			else
				write(HIC"\t�����ͣ�  "HIW"δ֪\n"NOR);
		}
	}

    inv = all_inventory(obj);
    if( sizeof(inv) ) {
        inv = map_array(inv, "inventory_look", this_object() );
        message("vision", sprintf("�����У�\n  %s\n",
            implode(inv, "\n  ") ), me);
    }
    return 1;
             }
}
int look_living(object me, object obj)
{
    int per_temp,i,j;
    string pro,*skills_name, str;
    mixed *inv;
    mapping my_fam, fam,skills;

	int my_lvl, your_lvl;
	string color ;

    if( me!=obj ){
    	if((int)me->query("shen") < 0)
        message("vision", me->name() + "������һ˫���ۣ���������Ķ����㿴��\n"NOR, obj);
        else if((int)me->query("shen") > 5000) 
        message("vision", me->name() + "������˫�ۣ�Ц���еĿ����㡣\n"NOR, obj);
        else if(random(10)>5) message("vision", me->name() + "�������㿴,��֪����ʲô��ͼ\n"NOR, obj);
        else message("vision", me->name() + "�������㿴,��֪���ڴ�Щʲô���⣡\n"NOR, obj);
                  }
    if (!objectp(present("fire", me))  && environment(me)->query("outdoors") && NATURE_D->outdoor_room() && !wizardp(me) ){
    str = sprintf( HIC"\n    �㿴��ǰ���ƺ��и���Ӱ������̫���ˣ������塣\n"NOR);
        write(str);
        return 1;
    }
    str = look_icon(me, obj) + obj->long();
    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	
    if( (string)obj->query("race")=="����" &&  intp(obj->query("age")) )
        str += sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number(obj->query("age") / 10 * 10));
	
    per_temp= (obj->query_per()>=30)?20:(obj->query_per()-10);
    if (per_temp<0) per_temp=0;
    if ( (string)obj->query("race")=="����" ) {
    if ( (string)obj->query("gender") == "Ů��")
        str += sprintf("%s����%s��\n", pro, look_level_girl[per_temp]);
    else
        str += sprintf("%s����%s��\n", pro, look_level_boy[per_temp]);
	
	// ��ʾ�ȼ�
	my_lvl = me->query("xyzx_sys/level");
	your_lvl = obj->query("xyzx_sys/level");
	color = NOR;
	if ( your_lvl-my_lvl < -5 ) color = WHT;
	else if ( your_lvl-my_lvl == 0 ) color = HIW;
	else if ( your_lvl-my_lvl < 5 ) color = HIG;
	else if ( your_lvl-my_lvl < 30 ) color = HIY;
	else if ( your_lvl-my_lvl < 100 ) color = HIR;
	else color = HIM;
	if ( your_lvl-my_lvl > 100 || (playerp(obj) && wizardp(me) && obj!=me) )
		str += sprintf("%s�������ƺ�����������"+color+" %s��"NOR"\n", pro, "������");
	else
		str += sprintf("%s�������ƺ�����������"+color+"%s��"NOR"\n", pro, chinese_number(your_lvl));

    skills=obj->query_skills();
    if (!sizeof(skills))
        str+=sprintf("%s�������ƺ������κ��书��\n", pro);
    else{
        skills_name=sort_array( keys(skills), (: strcmp :) );
        i=random(sizeof(skills_name));
                if (SKILL_D(skills_name[i])->type()=="knowledge")
            str+=sprintf("%s�������ƺ������κ��书��\n", pro);
        else
            str+=sprintf("%s���书�������ƺ�%s��\n", pro,"/cmds/usr/skills"->skill_level(SKILL_D(skills_name[i])->type(), skills[skills_name[i]]));
    }
    }
    // If we both has family, check if we have any relations.
if(obj!=me && obj->query("id")==me->query("couple/couple_id")){	
if(me->query("gender")=="Ů��") str+=pro+"������Ϲ���\n";	
else if (me->query("gender")=="����") str+=pro+"��������š�\n";	
}
    if( obj!=me
    &&  mapp(fam = obj->query("family"))
    &&  mapp(my_fam = me->query("family")) 
    &&  fam["family_name"] == my_fam["family_name"] ) {
    
        if( fam["generation"]==my_fam["generation"] ) {
            if( (string)obj->query("gender") == "����" )
                str += sprintf( pro + "�����%s%s��\n",
                    my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                    my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
            else
                str += sprintf( pro + "�����%s%s��\n",
                    my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                    my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
        } else if( fam["generation"] < my_fam["generation"] ) {
            if( my_fam["master_id"] == obj->query("id") )
                str += pro + "�����ʦ����\n";
            else if( my_fam["generation"] - fam["generation"] > 1 )
                str += pro + "�����ͬ�ų�����\n";
            else if( fam["enter_time"] < my_fam["enter_time"] )
                str += pro + "�����ʦ����\n";
            else
                str += pro + "�����ʦ�塣\n";
        } else {
            if( fam["generation"] - my_fam["generation"] > 1 )
                str += pro + "�����ͬ������\n";
            else if( fam["master_id"] == me->query("id") )
                str += pro + "����ĵ��ӡ�\n";
            else
                str += pro + "�����ʦֶ��\n";
        }
    }
    if( obj->query("max_qi") )
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";
    inv = all_inventory(obj);
    if( sizeof(inv) ) {
        inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
        inv -= ({ 0 });
        if( sizeof(inv) )
            str += sprintf( obj->is_corpse() ? "%s����������:\n%s\n" : "%s%s\n",
                            pro, implode(inv, "\n") );
        if (!obj->query_temp("armor/cloth") && obj->query("race")=="����" )
            str+=pro+"����"+YEL+"����"+NOR+"��ʲôҲû����\n";
    }   else    str += sprintf( obj->is_corpse() ? "%s��������ʲôҲû�С�\n" : (obj->query("race")=="����"?"%s����"+YEL+"����"+NOR+"��ʲôҲû����\n":"��������û���κζ�����\n"),pro);
if( me->query("position") == "webuser" ) {
printf(JSP "parent.look_living(\"%s\", \"%s\")" NSP, str,obj->query("id"));
} else {
    if (strlen(str)>8192)
    me->start_more(str);
    else     message("vision", str, me);
}
    if( obj!=me && living(obj)){
        i=obj->query("shen");
        j=me->query("shen");
        if ((i<-5000 && j>5000 ) || (i>5000 && j<-5000 ) ){
            write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
            COMBAT_D->auto_fight(obj, me, "berserk");
        }
    }
    return 1;
}
string inventory_look(object obj, int flag)
{
    string str;
     if( !flag )
        return "      "+obj->short();
    if( obj->query("equipped") ){
            switch( obj->query("armor_type") ) {
                case "cloth":
                case "armor":   str = "��";
				break;
                case "boots":   str = "�ŵ�";
				break;
                case "head":    str = "ͷ��";
				break;
                case "neck":    str = "��Χ";
				break;
                case "wrists":  str = "���";
				break;
                case "finger":  str = "ָ��";
				break;
                case "hands":   str = "�ִ�";
				break;
                case "waist":   str = "����";
				break;
				case "surcoat":   str = "����";
				break;
				case "pants":   str = "�ȴ�";
				break;
                default:    
				if ( environment(obj)->query_temp("weapon")==obj ) 
					str = "����ִ";
                 else 
					str = "����ִ";
            }
    str += "һ" + obj->query("unit")+obj->query("name")+"��";
    }
    return str;
}
int look_room_item(object me, string arg)
{
    object env;
    mapping item, exits;
    if( !objectp(env = environment(me)) )
        return notify_fail("����ֻ�л����ɵ�һƬ��ʲ��Ҳû�С�\n");
    if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
        if( stringp(item[arg]) )
            write(item[arg]);
        else if( functionp(item[arg]) )
            write((string)(*item[arg])(me));
            
        return 1;
    }
    if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
        if( objectp(env = find_object(exits[arg])) )
        {
            look_room(me, env);
            tell_room(env,"����̽ͷ̽�Ե�����������˼��ۡ�\n");
         }
        else {
            call_other(exits[arg], "???");
            look_room(me, find_object(exits[arg]));
        }
        return 1;
    }
    return notify_fail("��Ҫ��ʲ�᣿\n");
}
int help (object me)
{
    write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
    return 1;
}
