#pragma once

namespace mce {
	struct Color {
		union {
			struct { float r, g, b, a; };
			float arr[4]{};
		};
		bool shouldDelete = true;

		Color() {
			this->r = 1;
			this->g = 1;
			this->b = 1;
			this->a = 1;
		}
		Color(float x) {
			this->r = x;
			this->g = x;
			this->b = x;
			this->a = 1;
		}
		Color(const Color& other) {
			this->r = other.r;
			this->g = other.g;
			this->b = other.b;
			this->a = other.a;
			this->shouldDelete = other.shouldDelete;
		}
		Color(const float r, const float g, const float b, const float a = 255) {
			this->r = r / 255.0f;
			this->g = g / 255.0f;
			this->b = b / 255.0f;
			this->a = a / 255.0f;
		}
		Color(const int r, const int g, const int b, const int a = 255) {
			this->r = r / 255.0f;
			this->g = g / 255.0f;
			this->b = b / 255.0f;
			this->a = a / 255.0f;
		}
		Color(const float r, const float g, const float b, const float a, const bool shouldDelete) {
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
			this->shouldDelete = shouldDelete;
		}
	};
}