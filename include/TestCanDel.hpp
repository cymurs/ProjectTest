/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestCanDel.hpp
 * Author: root
 *
 * Created on 2017年10月16日, 上午9:30
 */

#ifndef TESTCANDEL_HPP
#define TESTCANDEL_HPP
#include "share.h"
#include <getopt.h>

void ProcessOptions(int argc, char **argv) ;

void Call() {
    int argc_new = 8;
    char **argv_new = new char *[argc_new];
    
    argv_new[0] = strdup("test");
    argv_new[1] = strdup("--variable_focal_length");
    argv_new[2] = strdup("--use_focal_estimate");
    argv_new[3] = strdup("--constrain_focal");
    argv_new[4] = strdup("--constrain_focal_weight");
    argv_new[5] = strdup("0.0001");
    argv_new[6] = strdup("--estimate_distortion");
    argv_new[7] = strdup("--run_bundle");
    
    ProcessOptions(argc_new, argv_new);
    
    for (int i = 0; i < argc_new; i++) {
        free(argv_new[i]);
    }

    delete[] argv_new;
}

void ProcessOptions(int argc, char **argv) 
{
	
    /* Read options */
    while (1) {
	static struct option long_options[] = {
	    {"fisheye",      1, 0, 'f'},
            {"intrinsics",   1, 0, 357}, //

	    {"init_pair1",   1, 0, 'p'},
	    {"init_pair2",   1, 0, 'q'},
	    {"output",       1, 0, 'o'},
	    {"output_all",   1, 0, 'a'},
	    {"init_focal_length",  1, 0, 'i'},
	    {"variable_focal_length", 0, 0, 'v'},
	    {"fixed_focal_length", 0, 0, 'x'},
	    {"run_bundle",   0, 0, 'r'},
	    {"rerun_bundle", 0, 0, 'j'},
	    {"slow_bundle",  0, 0, 'D'},
            {"skip_full_bundle", 0, 0, 321},//
            {"skip_add_points", 0, 0, 322},//

	    {"compress_list", 0, 0, '4'},
            {"scale_focal", 1, 0, 305},//
            {"scale_focal_file", 1, 0, 307},//

            {"write_tracks", 1, 0, 311},//
            {"rotate_cameras", 1, 0, 309},//
            {"zero_distortion_params",0, 0, 363},//
            {"enrich_points", 0, 0, 361},//
            {"output_relposes", 1, 0, 368},


            {"compute_color_statistics", 0, 0, 323},//
            {"detect_duplicates", 0, 0, 352},//
            {"bundle_from_tracks", 0, 0, 353},//
            {"bundle_from_points", 0, 0, 354},//
            {"stretch_factor", 1, 0, 356},//

            {"classify_photos", 0, 0, 324},//
            {"compare_histograms", 0, 0, 334},//
            {"panorama_mode", 0, 0, 332},
            {"use_fit_plane", 0, 0, 'l'},
            {"day_photos", 1, 0, 325},
            {"night_photos", 1, 0, 326},
            {"cloudy_photos", 1, 0, 327},
            {"projective_cameras", 1, 0, 315},
            {"projective_points", 1, 0, 316},
            {"prune_bad_points", 0, 0, 351},//

            

            {"compute_covariance", 0, 0, 340},//
            {"covariance_fix1", 1, 0, 341},//
            {"covariance_fix2", 1, 0, 342},//

	    {"ignore_file",  1, 0, 'L'},
	    {"use_focal_estimate", 0, 0, 'U'},
            {"trust_focal_estimate", 0, 0, '_'},
            {"estimate_ignored", 0, 0, 344},//
            {"reposition_scene", 0, 0, 'R'},//
            {"segment_sky", 1, 0, 350},//
            {"keypoint_border_width", 1, 0, 355},//
            {"keypoint_border_bottom", 1, 0, 365},//

	    {"min_track_views", 1, 0, 'V'},//
	    {"max_track_views", 1, 0, 320},//
            {"min_max_matches", 1, 0, 362},//
            {"min_feature_matches", 1, 0, 369},//

	    {"ray_angle_threshold", 1, 0, 'N'},
	    {"estimate_distortion", 0, 0, 347},
            {"distortion_weight", 1, 0, 348},//
	    {"construct_max_connectivity", 0, 0, '*'},//

	    {"homography_threshold", 1, 0, 'H'},//
	    {"homography_rounds",    1, 0, 345},//
	    {"fmatrix_threshold",    1, 0, 'F'},//
	    {"fmatrix_rounds",       1, 0, 'S'},//
            {"skip_fmatrix",         0, 0, 306},//
            {"skip_homographies",         0, 0, 319},//
	    {"projection_estimation_threshold", 1, 0, 'P'},
            {"min_proj_error_threshold", 1, 0, 317},
            {"max_proj_error_threshold", 1, 0, 318},
            {"use_angular_score", 0, 0, 349},//
            
	    {"up_image",             1, 0, 'E'},
	    {"estimate_up_vector_szeliski", 0, 0, 'Z'},
	    {"min_camera_distance_ratio", 1, 0, 'C'},//
	    // {"baseline_threshold",   1, 0, 'B'},
            {"optimize_for_fisheye",  0, 0, 'B'},//

            {"assemble",     0, 0, 308},//
	    {"bundle",       1, 0, 'b'},
            {"server_mode",  1, 0, 346},//
	    {"match_dir",    1, 0, 'm'},
            {"match_index_dir", 1, 0, 366},
            {"match_table",  1, 0, 364},
            {"image_dir",    1, 0, 300},//
            {"key_dir",      1, 0, 301},//

            {"analyze_matches", 0, 0, 'M'},//
            {"match_global", 0, 0, '<'},//
            {"ann_max_pts_visit", 1, 0, 302},//
            {"global_knn", 1, 0, 303},//
            {"global_nn_sigma", 1, 0, 304},//

	    {"output_dir",   1, 0, 'u'},
	    {"use_constraints", 0, 0, '=' },
	    {"constrain_focal", 0, 0, '$'},
	    {"constrain_focal_weight", 1, 0, 'J'},
	    {"only_bundle_init_focal", 0, 0, 'y'},//
            {"no_factor_essential", 0, 0, 339},//

	    {"point_constraint_file", 1, 0, 'Y'},//
	    {"point_constraint_weight", 1, 0, 'w'},//

	    {"fix_necker",   0, 0, 'n'},//
	    {"sift_binary",  1, 0, 's'},//
	    {"options_file", 1, 0, 'z'},
	    {"add_images",   1, 0, '@'},//

	    {"scale",        1, 0, '9'},
            {"morph_steps",  1, 0, '0'},
            {"image_rescale", 1, 0, '+'},

	    {"help",         0, 0, 'h'},

	    {0, 0, 0, 0}
	};

	int option_index;
	int c = getopt_long(argc, argv, "f:do:a:i:x",
			    long_options, &option_index);
   // cout<<" optarg=="<< optarg<<endl;//optargΪoption.txt��������Ĳ���,���Ϊ����Ҳ�������
	//cout<<"c==="<<c<<endl;
	if (c == -1)
	    break;
	
	switch (c) {
	    case 'h':
		/* Print usage */
		cout << "Param 'h'" << endl;
		exit(0);
		break;

	    case 'f':
		bool m_fisheye;
                             char *m_fisheye_params;
                             m_fisheye = true;
		printf("Using fisheye lens, param file: %s\n", optarg);
		m_fisheye_params = strdup(optarg);
		break;

            case 357:
                bool m_use_intrinsics;
                char *m_intrinsics_file;
                m_use_intrinsics = true;
                m_intrinsics_file = strdup(optarg);
                break;

            case 'p':
                int a;
                a = atoi(optarg);
                break;
            case 'q':
                int b;
                b = atoi(optarg);
                break;

            case 347:
                cout << "m_estimate_distortion = true" << endl;
		break;

            case 348:
                cout << atof(optarg) << endl;
		break;

            case 349:
                cout << "m_use_angular_score = true" << endl;
                break;

	    case '*':
		cout << "m_construct_max_connectivity = true" << endl;
		break;

	    case 'o':
		char *m_bundle_output_file;
                             m_bundle_output_file = strdup(optarg);
		break;
	    case 'a':
		char *m_bundle_output_base;
                             m_bundle_output_base = strdup(optarg);
		break;
	    case 'i':
		float m_init_focal_length;
                            m_init_focal_length = atof(optarg);
		break;
	    case 'v':
		cout << "m_fixed_focal_length = false" << endl;
		break;
	    case 'x':
		cout <<  "m_fixed_focal_length = true" << endl;
		break;
	    case 'r':
		cout << "m_run_bundle = true" << endl;
		break;
	    case 'j':
		cout << "m_rerun_bundle = true" << endl;
		break;

	    case 'D':
		cout << "m_fast_bundle = false" << endl;
		break;

	    case 321:
		cout <<  "m_skip_full_bundle = true" << endl;
		break;

	    case 322:
		cout << "m_skip_add_points = true" << endl;
		break;

	    case '4':
		cout << "m_compress_list = true" << endl;
		break;

            case 'R':
                cout <<  "m_reposition_scene = true" << endl;
                break;

            case 351:
                cout <<  "m_prune_bad_points = true" << endl;
                break;



            case 368:
                bool m_output_relposes;
                char *m_output_relposes_file;
                m_output_relposes = true;
                m_output_relposes_file = strdup(optarg);
                break;

            case 350:
                bool m_segment_sky;
                char *m_sky_model_file;
                m_segment_sky = true;
                m_sky_model_file = strdup(optarg);
                break;

            case 305:
                float m_scale_focal;
                m_scale_focal = atof(optarg);
                break;

            case 307:
                char *m_scale_focal_file;
                m_scale_focal_file = strdup(optarg);
                break;

            case 309:
                char *m_rotate_cameras_file;
                m_rotate_cameras_file = strdup(optarg);
                break;

            case 311:
                char *m_track_file;
                m_track_file = strdup(optarg);
                break;



            case 340:
                cout <<  "m_compute_covariance = true" <<endl;
                break;

            case 341:
                int m_covariance_fix1;
                m_covariance_fix1 = atoi(optarg);
                break;

            case 342:
                int m_covariance_fix2;
                m_covariance_fix2 = atoi(optarg);
                break;

#if 0
            case 352:
                m_detect_duplicates = true;
                break;
            
            case 353:
                m_bundle_from_tracks = true;
                break;

            case 354:
                m_bundle_from_points = true;
                m_bundle_from_tracks = true;
                break;

            case 356:
                m_stretch_factor = atof(optarg);
                break;
#endif

            case 355:
                int m_keypoint_border_width;
                m_keypoint_border_width = atoi(optarg);
                break;

            case 365:
                int m_keypoint_border_bottom;
                m_keypoint_border_bottom = atoi(optarg);
                break;

            case 344:
                cout << "m_estimate_ignored = true" << endl;
                break;

            case 363:
                cout <<  "m_zero_distortion_params = true" << endl;
                break;

            case 361:
                cout << "m_enrich_points = true" << endl;
                break;

        case 'L':
            char *m_ignore_file;
            m_ignore_file = strdup(optarg);
            break;

        case '@':
            char *m_add_image_file;
            m_add_image_file = strdup(optarg);
            break;



        case 'U':
            cout << "m_use_focal_estimate = true" << endl;
            break;

            case '_':
                cout <<  "m_trust_focal_estimate = true" << endl;
                break;

        case 'H':
            float m_homography_threshold;
            m_homography_threshold = atof(optarg);
            break;

        case 345:
            int m_homography_rounds;
            m_homography_rounds = atoi(optarg);
            break;

        case 'F':
            float m_fmatrix_threshold;
            m_fmatrix_threshold = atof(optarg);
            break;

        case 'S':
            int m_fmatrix_rounds;
            m_fmatrix_rounds = atoi(optarg);
            break;

            case 306:
                cout << "m_skip_fmatrix = true" << endl;
                break;

            case 319:
                cout << "m_skip_homographies = true" << endl;
                break;

        case 'P':
            float m_projection_estimation_threshold;
            m_projection_estimation_threshold = atof(optarg);
            break;

        case 317:
            float m_min_proj_error_threshold;
            m_min_proj_error_threshold = atof(optarg);
            break;

        case 318:
            float m_max_proj_error_threshold;
            m_max_proj_error_threshold = atof(optarg);
            break;

        case 'C':
            float m_min_camera_distance_ratio;
            m_min_camera_distance_ratio = atof(optarg);
            break;

        case 'B':
            // m_baseline_threshold = atof(optarg);
            cout << "m_optimize_for_fisheye = true" << endl;
            break;

        case 'E':
            int m_up_image;
            m_up_image = atoi(optarg);
            break;

#if 0
	    case 'T':
		m_start_camera = atoi(optarg);
		break;
#endif

	    case 'V':
		int m_min_track_views;
                             m_min_track_views = atoi(optarg);
		break;

	    case 320:
		int m_max_track_views;
                             m_max_track_views = atoi(optarg);
		break;

            case 362:
                int m_min_max_matches;
                m_min_max_matches = atoi(optarg);
                break;

            case 369:
                int m_min_num_feat_matches;
                m_min_num_feat_matches = atoi(optarg);
                break;

        case 'N':
            float m_ray_angle_threshold;
            m_ray_angle_threshold = atof(optarg);
            break;

            case 308: /* assemble */
                cout << "m_assemble = true" << endl;
                break;

            case 346:
                int m_server_port;
                cout << " m_server_mode = true" << endl;
                m_server_port = atoi(optarg);
                break;

        case 'b':
            bool m_bundle_provided;
            char *m_bundle_file;
            m_bundle_provided = true;
            m_bundle_file = strdup(optarg);
            break;

        case 'm':
            char *m_match_directory;
            m_match_directory = strdup(optarg);
            break;
        case 366:
            char *m_match_index_dir;
            m_match_index_dir = strdup(optarg);
            break;
        case 364:
            char *m_match_table;
            m_match_table = strdup(optarg);
            break;
        case 300:
            char *m_image_directory;
            m_image_directory = strdup(optarg);
            break;

        case 301:
            char *m_key_directory;
            m_key_directory = strdup(optarg);
            break;
        case 'M':
            cout << "m_analyze_matches = true" << endl;
            break;

        case 332:
            cout << "m_panorama_mode = true" << endl;
            break;

        case 339:
            cout << "m_factor_essential = false" << endl;
            break;

        case '<':
            cout <<  "m_match_global = true" << endl;
            break;

        case 302:
            int m_ann_max_pts_visit;
            m_ann_max_pts_visit = atoi(optarg);
            printf("  ann_max_pts_visit: %d\n", m_ann_max_pts_visit);
            break;
        case 303:
            int m_global_knn;
            m_global_knn = atoi(optarg);
            printf("  global_knn: %d\n", m_global_knn);
            break;
        case 304:
            float m_global_nn_sigma;
            m_global_nn_sigma = atof(optarg);
            printf("  global_nn_sigma: %0.3f\n", m_global_nn_sigma);
            break;

        case 'u':
            char *m_output_directory;
            m_output_directory = strdup(optarg);
            break;
        case '=':
            cout << "m_use_constraints = true" << endl;
            break;
        case '$':
            cout << "m_constrain_focal = true" << endl;
            break;
        case 'J':
            float m_constrain_focal_weight;
            m_constrain_focal_weight = atof(optarg);
            cout << "m_constrain_focal_weight = " << m_constrain_focal_weight << endl;
            break;
        case 'y':
            cout << "m_only_bundle_init_focal = true" << endl;
            break;

        case 'Y':
            char *m_point_constraint_file;
            m_point_constraint_file = strdup(optarg);
            break;

        case 'w':
            float m_point_constraint_weight;
            m_point_constraint_weight = atof(optarg);
            break;

        case 'n':
            cout << "m_fix_necker = true";
            break;
        case 's':
            char *m_sift_binary;
            m_sift_binary = strdup(optarg);
            break;

        case 'Z':
            cout <<  "m_estimate_up_vector_szeliski = true" << endl;
            break;

        case '9':
            float m_scale;
            m_scale = atof(optarg);
            break;

        case 'W':
            cout << "m_metric = true" << endl;
            break;

        case 'z': {
            int optind_curr = optind;
            std::vector<std::string> tokens;
            char *filename;
            FILE* f;
            char *opt_str;
            
            optind = 1;

            /* Load options from file */
            filename = optarg;
            f = fopen(optarg, "r");
            if (f == NULL) {
                printf("Error reading options file %s\n", filename);
                exit(1);
            }

            opt_str = new char[4096];
            fread(opt_str, 1, 4096, f);
            fclose(f);

            std::string str(opt_str);
            // wxStringTokenizer t(str, wxT(" \n"));
            //Tokenize(str, tokens, " \n");
            cout << "Tokenize(str, tokens, '\n')" << endl;

#if 0
            while (t.HasMoreTokens()) {
                wxString tok = t.GetNextToken();
                tokens.push_back(tok);
            }
#endif

            int argc_new = (int) tokens.size() + 1;
            char **argv_new = new char * [argc_new];

            argv_new[0] = strdup("test");
            for (int i = 1; i < argc_new; i++) {
                argv_new[i] = strdup(tokens[i-1].c_str());
            }

            ProcessOptions(argc_new, argv_new);

            for (int i = 0; i < argc_new; i++) {
                free(argv_new[i]);
            }

            delete [] argv_new;
            delete [] opt_str;

            optind = optind_curr;

#ifdef WIN32
    return;
#else
            break;
#endif
        }

        default:
            printf("Unrecognized option %d\n", c);
            break;
        }
    }
}

#endif /* TESTCANDEL_HPP */

